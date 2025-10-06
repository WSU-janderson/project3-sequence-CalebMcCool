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

    cout << "Creating Sequence 1" << endl;
    Sequence s1(3);
    cout << s1.size() << endl;
    s1.push_back("hello");
    s1.push_back("Goodbye");
    s1.push_back("Some Element");
    s1.push_back("Again Element");
    s1.push_back("Last Element");

    cout << s1.front() << endl;

    someString = s1[1];
    cout << someString;

    return 0;
}