/** @mainpage
 *
 * CISC 2200: Data Structures<br/>
 * Project 2: Extending the Bag ADT<br/>
 *
 * <p>This program tests the <code>VectorBag</code> class.  It is a
 * modification of the program given in Section&nbsp;3.2 of the text,
 * which tests the <code>ArrayBag</code> class.</p>
 *
 * <p>In addition to testing the operations that VectorBag implements
 * from the abstract BagInterface class, it tests the set-like
 * operations of union, intersection, and difference.</p>
 *
 * <p>(Based on Exercises&nbsp;1.6-1.8, along with Programming
 * Problem&nbsp;3.5.)</p>
 *
 * @author
 * @date
 * @file proj2.cpp
 *
 **********************************************************************/

// usual front matter (includes, declarations)

#include <algorithm>
#include <iostream>
#include <string>
#include "VectorBag.h"
#include "VectorBag.cpp"

using namespace std;

template<class ItemType> void displayBag(VectorBag<ItemType>& bag);
template<class ItemType> void bagTester(VectorBag<ItemType>& bag);
void newOpsTester();

/**
 * The usual <code>main()</code> function.
 */
int main()
{
    VectorBag<string> bag;
    cout << "Testing the Vector-Based Bag:" << endl;
    cout << "The initial bag is empty." << endl;
    bagTester(bag);
    newOpsTester();
    cout << "All done!" << endl;
    
    return 0;
}

/**
 * Display the contents of a <code>VectorBag</code>, which can hold
 * any kind of element.  The elements are displayed in sorted order.
 * (This means that the <code>ItemType</code> must be one for which
 * the&nbsp;"&lt;" operation is defined.)
 * @param bag The bag to be displayed.
 */
template<class ItemType>
void displayBag(VectorBag<ItemType>& bag)
{
    cout << "The bag contains " << bag.getCurrentSize()
    << " items:" << endl;
    vector<ItemType> bagItems = bag.toVector();
    
    int numberOfEntries = static_cast<int>(bagItems.size());
    sort(bagItems.begin(), bagItems.end());
    
    for (int i = 0; i < numberOfEntries; i++)
        cout << bagItems[i] << " ";
    cout << endl << endl;
}  // end displayBag

/**
 * This is an adaption of the <code>bagTester</code> function in
 * Carrano-Henry <code>main.cpp</code>, which tests the
 * <code>ArrayBag</class>.  The changes are as follows:
 * <ol>
 * <li> Whereas the original version assumed that
 * the <code>ArrayBag</code> contained <code>string</code>, our
 * version allows the <code>VectorBag</code> to contain any kind of
 * item.</li>
 * <li> In addition to testing the original operations that are
 * implemented from <code>BagInterface</code>, we test the operations
 * of union, intersection, and difference.</li>
 * </ol>
 * @param bag The bag to be tested.
 */
template<class ItemType> void bagTester(VectorBag<ItemType>& bag)
{
    cout << "isEmpty: returns " << bag.isEmpty()
    << "; should be 1 (true)" << endl;
    displayBag(bag);
    
    string items[] = {"one", "two", "three", "four", "five", "one"};
    unsigned int itemsSize = sizeof(items)/sizeof(items[0]);
    cout << "Adding " << itemsSize << " items to the bag: " << endl;
    for (unsigned int i = 0; i < itemsSize; i++)
        bag.add(items[i]);
    
    displayBag(bag);
    
    cout << "isEmpty: returns " << bag.isEmpty()
    << "; should be 0 (false)" << endl;
    
    cout << "getCurrentSize: returns " << bag.getCurrentSize()
    << "; should be " << itemsSize << endl;
    
    cout << "Try to add another entry: add(\"extra\") returns "
    << bag.add("extra") << endl;
    
    cout << "contains(\"three\"): returns " << bag.contains("three")
    << "; should be 1 (true)" << endl;
    cout << "contains(\"ten\"): returns " << bag.contains("ten")
    << "; should be 0 (false)" << endl;
    cout << "getFrequencyOf(\"one\"): returns "
    << bag.getFrequencyOf("one") << " should be 2" << endl;
    cout << "remove(\"one\"): returns " << bag.remove("one")
    << "; should be 1 (true)" << endl;
    cout << "getFrequencyOf(\"one\"): returns "
    << bag.getFrequencyOf("one") << " should be 1" << endl;
    cout << "remove(\"one\"): returns " << bag.remove("one")
    << "; should be 1 (true)" << endl;
    cout << "remove(\"one\"): returns " << bag.remove("one")
    << "; should be 0 (false)" << endl;
    cout << endl;
    
    displayBag(bag);
    
    cout << "After clearing the bag, ";
    bag.clear();
    
    cout << "isEmpty: returns " << bag.isEmpty()
    << "; should be 1 (true)" << endl;
}  // end bagTester

/**
 * Test the new VectorBag operations (union, intersection, difference)
 */

void newOpsTester()
{
    cout << "\nLet's test the new bag operations.\n\n";
    int firstItems[] = {2, 4, 6, 6, 8, 10, 12, 15, 15};
    VectorBag<int> firstBag;
    int firstSize = sizeof(firstItems)/sizeof(int);
    cout << "Adding " << firstSize << " items to first bag: " << endl;
    for (int i = 0; i < firstSize; i++)
        firstBag.add(firstItems[i]);
    cout << "First bag: ";
    displayBag(firstBag);
    
    int secondItems[] = {3, 6, 9, 12, 12, 15, 15, 18};
    VectorBag<int> secondBag;
    int secondSize = sizeof(secondItems)/sizeof(int);
    cout << "Adding " << secondSize << " items to second bag: " << endl;
    for (int i = 0; i < secondSize; i++)
        secondBag.add(secondItems[i]);
    cout << "Second bag: ";
    displayBag(secondBag);
    
    VectorBag<int> unionBag = firstBag + secondBag;
    cout << "firstBag union secondBag: \n";
    displayBag(unionBag);
    
    
    VectorBag<int> intersectBag = firstBag * secondBag;
    cout << "firstBag intersect secondBag: \n";
    displayBag(intersectBag);
    
    VectorBag<int> diffBag = firstBag - secondBag;
    cout << "firstBag minus secondBag: \n";
    displayBag(diffBag);
    
    diffBag = secondBag - firstBag;
    cout << "secondBag minus firstBag: \n";
    displayBag(diffBag);
    
}

/* --SAMPLE RUN--
 Testing the Vector-Based Bag:
 The initial bag is empty.
 isEmpty: returns 1; should be 1 (true)
 The bag contains 0 items:
 
 
 Adding 6 items to the bag:
 The bag contains 6 items:
 five four one one three two
 
 isEmpty: returns 0; should be 0 (false)
 getCurrentSize: returns 6; should be 6
 Try to add another entry: add("extra") returns 1
 contains("three"): returns 1; should be 1 (true)
 contains("ten"): returns 0; should be 0 (false)
 getFrequencyOf("one"): returns 2 should be 2
 remove("one"): returns 1; should be 1 (true)
 getFrequencyOf("one"): returns 1 should be 1
 remove("one"): returns 1; should be 1 (true)
 remove("one"): returns 0; should be 0 (false)
 
 The bag contains 5 items:
 extra five four three two
 
 After clearing the bag, isEmpty: returns 1; should be 1 (true)
 
 Let's test the new bag operations.
 
 Adding 9 items to first bag:
 First bag: The bag contains 9 items:
 2 4 6 6 8 10 12 15 15
 
 Adding 8 items to second bag:
 Second bag: The bag contains 8 items:
 3 6 9 12 12 15 15 18
 
 firstBag union secondBag:
 The bag contains 17 items:
 2 3 4 6 6 6 8 9 10 12 12 12 15 15 15 15 18
 
 firstBag intersect secondBag:
 The bag contains 3 items:
 6 12 15
 
 firstBag minus secondBag:
 The bag contains 6 items:
 2 4 8 10 15 15
 
 secondBag minus firstBag:
 The bag contains 7 items:
 3 9 12 12 15 15 18
 
 All done!
 Program ended with exit code: 0
 
 */

