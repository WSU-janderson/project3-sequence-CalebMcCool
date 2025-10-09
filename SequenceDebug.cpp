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
#include <exception>

using namespace std;

int main() {
    std::string someString = "";

    cout << "Your project is ready to go!" << endl;

    cout << "Creating Sequence 1..." << endl;

    Sequence s1(0);
    s1.push_back("Element 0");
    s1.push_back("Element 1");
    s1.push_back("Element 2");
    s1.push_back("Element 3");
    s1.push_back("Element Last");
    cout << "Creating Sequence 1..." << endl;
    cout << s1 << endl;

    Sequence s2(0);
    s2.push_back("Pasta 0");
    s2.push_back("Yam 1");
    s2.push_back("Yak 2");
    s2.push_back("Orange 3");
    s2.push_back("Lemon Last");
    cout << "Creating Sequence 2..." << endl;
    cout << s2 << endl;
    s2.clear();
    cout << "Clearing Sequence 2..." << endl;
    cout << s2 << endl;
    s2.push_back("test item right here");
    cout << s2 << endl;
    cout << s1 << endl;
    cout << "removing element 2" << endl;
    s1.erase(2);
    cout << s1 << endl;




    return 0;
}