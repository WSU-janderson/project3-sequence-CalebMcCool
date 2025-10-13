//-------------------------------------------
// Sequence.h is the header file to define variables and functions within Sequence.cpp
// Created by: Caleb McCool
// Date: October 13, 2025
//-------------------------------------------

#ifndef Sequence_h
#define Sequence_h
#include <cstdlib>
#include <string>
#include <exception>
#include <iostream>

class SequenceNode {
private:

public:
    SequenceNode* prev;
    SequenceNode* next;
    std::string item;
    SequenceNode();
    SequenceNode(std::string);
};

class Sequence{
private:
    size_t sequenceLength;
    SequenceNode* sequenceHead;
    SequenceNode* sequenceTail;

public:
    Sequence(size_t sz = 0);
    Sequence(const Sequence& s);
    ~Sequence();
    Sequence& operator=(const Sequence& s);

    std::string& operator[] (size_t position);
    void push_back(std::string item);
    void pop_back();
    void insert(size_t position, std::string item);
    std::string front() const;
    std::string back() const;
    bool empty() const;
    size_t size() const;
    void clear();
    void erase(size_t position);
    void erase(size_t position, size_t count);

    friend std::ostream& operator<<(std::ostream& os, const Sequence& s);

};

#endif