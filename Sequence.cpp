//-------------------------------------------
// Created By: Caleb McCool
// Date: October 13, 2025
//
// SequenceNode:
//   This is a single element of a sequence. It holds the data:
//    prev: pointer to the previous node
//    next: pointer to the next node
//    item: a string
// Sequence:
//  This is a collection of SequenceNodes in consecutive order.
//  It contains the data:
//    sequenceHead: a pointer to the head of the sequence
//    sequenceTail: a pointer to the tail of the sequence
//-------------------------------------------
#include "Sequence.h"
#include <cstdlib>
#include <string>
#include <exception>
#include <iostream>


// Constructor for a SequenceNode without Data
SequenceNode::SequenceNode() :
    prev(nullptr),
    next(nullptr)
{
}

// Constructor for a SequenceNode with Data
SequenceNode::SequenceNode(std::string item) :
    prev(nullptr),
    next(nullptr),
    item(item)
    {
}

// Constructor for a Sequence with Size
Sequence::Sequence(size_t sz) :
    sequenceLength(0),
    sequenceHead(nullptr),
    sequenceTail(nullptr) {

    for (size_t i=0; i<sz; i++){
        this->push_back("");
    }

}

// Constructor for a deep copy of Sequence
Sequence::Sequence(const Sequence& s):
    sequenceLength(0),
    sequenceHead(nullptr),
    sequenceTail(nullptr){

    SequenceNode* current;
    current = s.sequenceHead;
    while(current != nullptr){
        this->push_back(current->item);
        current = current->next;
    }

}

//Deconsructor for Sequence
Sequence::~Sequence(){
    clear();
}

//Operator '=' Overload for Sequence
Sequence& Sequence::operator=(const Sequence& s) {
    if (this == &s) {
        return *this;
    }
    clear();
    SequenceNode *current = s.sequenceHead;
    while (current != nullptr) {
        push_back(current->item);
        current = current->next;
    }
    return *this;
}

//Operator '[]' overload for Sequence
std::string& Sequence::operator[] (size_t position){
    if (position >= 0 && position <= sequenceLength){
        SequenceNode* current;
        current = sequenceHead;

        //Offseting the goal by 1 since sequence head already 1 iteration through the list
        for (size_t i=0; i<position; i++){
            current = current->next;
        }
        return current->item;

    } else {
        throw std::exception();
    }
}

//push_back for Sequence adds a node to the end of the Sequence
void Sequence::push_back(std::string item){
    SequenceNode* newNodePtr;
    newNodePtr = new SequenceNode;

    //set new node's variable fields
    newNodePtr->next = nullptr;
    newNodePtr->item = item;

    //Assigning node to last node in the sequence's next field
    if(this->sequenceHead == nullptr){
        this->sequenceHead = newNodePtr;
    } else {
        SequenceNode* current;
        current = sequenceHead;

        while (current->next != nullptr){
            current = current->next;
        }

        //Assigning last node's next field to the new node
        current->next = newNodePtr;
        newNodePtr->prev = current;
        //Assigning tail to the new node
        this->sequenceTail = newNodePtr;
    }

    sequenceLength++;

}

//pop_back for Sequence deletes node at the end of the Sequence
void Sequence::pop_back(){
    if (sequenceHead != nullptr){
        sequenceTail = sequenceTail->prev;
        sequenceLength--;

        SequenceNode* current;
        current = sequenceHead;

        //for loop set at one because sequenceHead is already 1
        for (size_t i=1; i<sequenceLength; i++){
            current = current->next;
        }
        current->next = nullptr;
    }
}

//insert for Sequence inserts node somewhere than pushes the nodes ahead
void Sequence::insert(size_t position, std::string item){
    if (position >= 0 && position <= sequenceLength){

        SequenceNode* insertNode = new SequenceNode(item);

        //Inserting at the head
        if (position == 0){
            insertNode->next = sequenceHead;

            if (sequenceHead != nullptr){
                sequenceHead->prev = insertNode;
            }

            if (sequenceLength == 0){
                sequenceTail = insertNode;
            }
            sequenceHead = insertNode;

        } else{
            SequenceNode* current;
            current = sequenceHead;
            for(size_t i=0; i < position; i++){
                current = current->next;
            }

            insertNode->prev = current->prev;
            insertNode->next = current;
            if (insertNode->prev != nullptr){
                insertNode->prev->next = insertNode;
            }
            if (insertNode->next != nullptr){
                insertNode->next->prev = insertNode;
            }
        }

    } else {
        throw std::exception();
    }
    sequenceLength++;
}

//Return first element
std::string Sequence::front() const{
    if (this->sequenceHead != nullptr){
        //SequenceNode* firstElement;
        return this->sequenceHead->item;
    }
}

//Return Last element
std::string Sequence::back() const{
    SequenceNode* current = sequenceHead;
    while (current->next != nullptr){
        current = current->next;
    }
    return current->item;
}

//Returns boolean of if empty
bool Sequence::empty() const{
    if (sequenceHead != nullptr){
        return false;
    } else{
        return true;
    }
}

//Size of Sequence
size_t Sequence::size() const {
    return sequenceLength;
}

//Clear the Sequence
void Sequence::clear(){
    SequenceNode* current = sequenceHead;
    while (current != nullptr){
        SequenceNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    sequenceHead = nullptr;
    sequenceTail = nullptr;
    sequenceLength = 0;
}

//Erase one Node
void Sequence::erase(size_t position){
    //Throwing exception if position > sequence Length
    if (position >= sequenceLength){
        throw std::exception();
    }
    //Walking down Sequence
    SequenceNode* current = sequenceHead;
    for (size_t i=0; i<position; i++){
        current = current->next;
    }
    //Configuring prev node
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        sequenceHead = current->next;
    }
    //Configuring next node
    if (current->next != nullptr){
        current->next->prev = current->prev;
    } else {
        sequenceTail = current->prev;
    }

    delete current;
    sequenceLength--;
}

//Erase a line of nodes
void Sequence::erase(size_t position, size_t count){
    if (count == 0){
        return;
    }
    if (position >= sequenceLength){
        throw std::exception();
    }
    if ((position + count) > sequenceLength){
        throw std::exception();
    }
    for (size_t i=0; i<count; i++){
        erase(position);
    }
}

//Overloads the << operator to print out custom message outputting
// sequence elements.
std::ostream& operator<<(std::ostream& os, const Sequence& s){
    os << "<";
    SequenceNode* current = s.sequenceHead;
    while (current != nullptr){
        os << current->item;
        if (current->next != nullptr){
            os << ", ";
        }
        current = current->next;
    }
    os << ">";
    return os;
}