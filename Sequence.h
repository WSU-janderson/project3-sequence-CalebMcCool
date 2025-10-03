#ifndef Sequence_h
#define Sequence_h
#include <cstdlib>
#include <string>

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
    //Need to: add in sequenceHead and sequenceTail
    int sequenceLength;
    SequenceNode* sequenceHead;
    SequenceNode* sequenceTail;

public:
    Sequence(size_t sz = 0);
    Sequence(const Sequence& other);


    void push_back(std::string item);
    std::string front() const;
    size_t size() const;


};

#endif