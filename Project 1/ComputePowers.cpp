// Abadali Sheikh
/** @mainpage
 *
 * CISC 2200: Data Structures<br/>
 * Project 1: Computing Powers<br/>
 *
 * <p>Put Compares the 3 different functions for powers.</p>
 *
 * @author Harry Q. Bovik, PhD
 * @date 35 Octember 12345
 * @file proj1.cc
 *
 **********************************************************************/

#include <iostream>
using namespace std;

// function prototypes


template <class T>
T power1(T x, unsigned int n, unsigned int& mults);

template <class T>
T power2(T x, unsigned int n, unsigned int& mults);

template <class T>
T power3(T x, unsigned int n, unsigned int& mults);

template <class T>
void printReport(T base, unsigned int pow,
                 T result1, T result2, T result3,
                 unsigned int mults1, unsigned int mults2,
                 unsigned int mults3);

/**
 * The usual main function.
 *
 * It computes the powers 2<sup><em>i</em></sup> for
 * <em>i=</em>0,1,2,..,32 via all three methods, reporting the number
 * of multiplications needed for each method.  (Note what happens for
 * 2^32.)  It then does likewise for 0.5<sup><em>i</em></sup>, but now
 * with <em>i=</em>0,1,2,...64
 *
 */
int main()
{
    unsigned int mults1, mults2, mults3;
    cout << "Test for integer base:\n";
    for (unsigned int pow = 0; pow <= 32; pow++) {
        unsigned int base = 2;
        unsigned int result1 = power1(base, pow, mults1);
        unsigned int result2 = power2(base, pow, mults2);
        unsigned int result3 = power3(base, pow, mults3);
        printReport(base, pow, result1, result2, result3,
                    mults1, mults2, mults3);
    }
    cout << "\nTest for floating-point base:\n";
    for (unsigned int pow = 0; pow <= 64; pow++) {
        double base = 0.5;
        double result1 = power1(base, pow, mults1);
        double result2 = power2(base, pow, mults2);
        double result3 = power3(base, pow, mults3);
        printReport(base, pow, result1, result2, result3,
                    mults1, mults2, mults3);
    }
}

/**
 * Iterative function to compute a power <em>x<sup>n</sup></em>.
 *
 * @param x is the base
 * @param n is the power of x
 * @param mults is the muiltiplications used
 * @return n
 * @pre n >= 0
 * @post mults is the total number of multiplications used
 */
template <class T>
T power1(T x, unsigned int n, unsigned int& mults)
{
    mults = 0;
    
    T result = x;
        if(n == 0){
             return 1;
        }
        if (n==1){
            return x;
        }
        else {
            for (int i = 1; i < n; i++) {
                result *=x;
                mults++;
            }
        }
        //result = x * power1(x, n - 1, mults);
    
    return result;
}

/**
 * A function that computes a^n to a*a^(n-1)
 * @param x is the power
 * @param n is the exponent
 * @param multi is total of multiplications used that is assumed to be set by the pervious
 * recursive functions.
 * @return n
 * @pre n >= 0
 * @post multi is the new number of multiplications used
 */

template <class T>
T power2(T x, unsigned int n, unsigned int& mults)
{
    mults = 0;
    
    if (n ==0)
        return 1;
    if (n==1)
        return x;
    
    T result = x*power2(x, n-1, mults);
    mults++;
    
    return result;
}

/**
 * @param x is the power
 * @param n is the exponent
 * @param multi is total of multiplications 
 * @return a^n
 * @pre n >= 0
 * @post multi is the new number of multiplications used
 */

template <class T>
T power3(T x, unsigned int n, unsigned int& mults)
{
    mults = 0;
    
    if (n==0)
        return 1;
    if (n==1)
        return x;
    if (n%2 ==0)
    {
        T result = power3(x, n/2, mults);
        mults++;
        
        return result * result;
    }
    else
    {
        T result = power3(x, n/2, mults);
        mults +=2;
        
        return result * result *x;
    }
}

/**
 * Report the results of three different exponentiation calculations.
 *
 * To give you practice using doxygen, I'll let you fill in the rest
 * of this comment block yourself.
 */

template <class T>
void printReport(T base, unsigned int pow,
                 T result1, T result2, T result3,
                 unsigned int mults1, unsigned int mults2,
                 unsigned int mults3)
{
    cout << base << "^" << pow << " = ";
    if (result1 == result2 && result2 == result3)
        cout << result1 << ": ";
    else
        cout << "(" << result1 << ", " << result2 << ", " << result3
        << ") [ERROR!]: ";
    cout << "mults1 = " << mults1 << ", mults2 = " << mults2
    << ", mults3 = " << mults3 << endl;
}






