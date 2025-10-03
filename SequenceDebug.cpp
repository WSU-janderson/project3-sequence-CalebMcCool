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
    cout << "Your project is ready to go!" << endl;

    cout << "Creating Sequence 1" << endl;
    Sequence s1(1);
    cout << s1.size() << endl;


    return 0;
}