/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 * Caleb McCool
 *
 * This is the debugging file used to test Sequence
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
    cout << s1 << endl;

    cout << "Creating Sequence 2..." << endl;
    Sequence s2(0);
    s2.push_back("Pasta 0");
    s2.push_back("Yam 1");
    s2.push_back("Chicken 2");
    s2.push_back("Orange 3");
    s2.push_back("Lemon Last");
    cout << s2 << endl;


    return 0;
}