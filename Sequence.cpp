#include "Sequence.h"
#include <cstdlib>
#include <string>

SequenceNode::SequenceNode() :
    prev(nullptr),
    next(nullptr)
{

}

SequenceNode::SequenceNode(std::string item) :
    prev(nullptr),
    next(nullptr),
    item(item)
    {

}


//Constructor for Sequence
Sequence::Sequence(size_t sz) :
    sequenceLength(sz),
    sequenceHead(nullptr),
    sequenceTail(nullptr) {

}

//Constructor for Deep Copy
Sequence::Sequence(const Sequence& s) :
    sequenceLength(s.sequenceLength){

}

//Add node to sequence
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

}

void Sequence::pop_back(){
    if (sequenceHead != nullptr){
        sequenceTail = sequenceTail->prev;
        --sequenceLength;

        SequenceNode* current;
        current = sequenceHead;

        //for loop set at one because sequenceHead is already 1
        for (int i=1; i<sequenceLength; i++){
            current = current->next;
        }
        current->next = nullptr;
    }
}

//Return first element
std::string Sequence::front() const{
    if (this->sequenceHead != nullptr){
        SequenceNode* firstElement;
        return this->sequenceHead->item;
    }
}

//Size of Sequence
size_t Sequence::size() const {
    return sequenceLength;
}