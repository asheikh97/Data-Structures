/**
 * @file proj4.cc
 * \mainpage
 *
 * CISC 2200, Data Structures<br>
 * Project 4: The Banking Simulation<p>
 *
 * Brief discussion
 * This program reads data from input file and outputs arrival & departure times.
 * @author Abadali Sheikh
 * @date 11/29/17
 
 SAMPLE RUN
 g++ main.cpp && ./a.out data-0.txt
 Processing an arrival event at time:   20
 Processing an arrival event at time:   22
 Processing an arrival event at time:   23
 Processing a departure event at time:  26
 Processing a departure event at time:  30
 Processing an arrival event at time:   30
 Processing a departure event at time:  32
 Processing a departure event at time:  35
 
 Final statistics:
 Total number of people processed: 4
 Average amount of time spent waiting: 3.25
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;

struct Event
{
    int time;
    int waitingTime;
    Event(int t, int w);
};

Event::Event(int t, int w)
{
    time = t;
    waitingTime = w;
}

struct EventList
{
    int numCustomers;
    priority_queue<Event> events;
    void fill(istream& is);
    void simulate();
};

bool operator<(const Event &first, const Event &second)
{
    return second.time < first.time;
}

/**
 * The usual main function
 */
int main(int argc, char** argv)
{
    EventList eventList;
    // command-line parameter munging
    // also fills the event list with the input data
    char* progname = argv[0];          // simplify msgs a bit
    switch (argc) {
        case 1:
            eventList.fill(cin);
            break;
        case 2: {
            ifstream ifs(argv[1]);
            if (!ifs) {
                cerr << progname << ": couldn't open " << argv[1] << endl;
                return 1;
            }
            eventList.fill(ifs);
            break;
        }
        default:
            cerr << "Usage: " << progname << " [datafile]\n";
            return 2;
    }
    
    eventList.simulate();
}

void EventList::fill(istream& is)
{
    int arrivalTime = 0;
    int recentTime = 0;
    int time = 0;
    //create a constructor customer for Event
    Event customer(arrivalTime, time);
    numCustomers = 0;
    
    //read data from file
    while(is >> arrivalTime >> time)
    {
        numCustomers++; //number of customers
        //set new customer to recent time
        recentTime = customer.time;
        customer.time = arrivalTime;
        customer.waitingTime = time;
        if(recentTime > customer.time)
        {
            cout << "customer #" << numCustomers << " out of order (time = "
            << customer.time << ", previous time = " << recentTime << ")" << endl;
            exit(1);
        }
        events.push(customer);
    }
}

void EventList::simulate()
{
    int open_time = 0;
    int total_wait = 0;
    double averageTime = 0.0;
    
    while(!events.empty())
    {
        Event Evn = events.top();
        events.pop();
        if(Evn.waitingTime >= 0)
        {
            open_time = max(Evn.time, open_time);
            total_wait += open_time - Evn.time;
            open_time += Evn.waitingTime;
            Event depart(open_time, -1); //newDepartureEvent = a new departure event with departureTime
            events.push(depart);
            cout << "Processing an arrival event at time:"
                 << setw(5) << Evn.time << endl;
        }
        else {
            cout << "Processing a departure event at time:"
                 << setw(4) << Evn.time  << endl;
        }
    }
    averageTime = (double)total_wait/numCustomers;
    cout << endl << "Final statistics:" << endl;
    cout << "Total number of people processed: " << numCustomers << endl;
    cout << "Average amount of time spent waiting: " << averageTime << endl;
}
