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
Sequence::Sequence(const Sequence& other) :
    sequenceLength(other.sequenceLength){

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

        current->next = newNodePtr;
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