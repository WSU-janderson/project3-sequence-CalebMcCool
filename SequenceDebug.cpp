/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */

#include "Sequence.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    std::string someString = "";

    cout << "Your project is ready to go!" << endl;

    cout << "Creating Sequence 1..." << endl;
    Sequence s1(1);
    cout << s1.size() << endl;
    s1.push_back("Element 0");
    s1.push_back("Element 1");
    s1.push_back("Element 2");
    s1.push_back("Element 3");
    s1.push_back("Element Last");

    cout << "front: " << s1.front() << endl;
    Sequence s2(s1);
    cout << "Deep Copy Created... " << s1.front() << endl;
    cout << "Sequence 1 Element 2: " << s1[2] << " Address: " << &(s1[2]) << endl;
    cout << "Sequence 2 Element 2: " << s2[2] << " Address: " << &(s2[2]) << endl;
    cout << "--------Testing Insert-----------" << endl;

    cout << "Before: " << endl;
    s1.insert(2, "test");
    cout << "After: " << endl;


    return 0;
}