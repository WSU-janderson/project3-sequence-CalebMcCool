#include "Sequence.h"
#include <cstdlib>
#include <string>

Sequence::Sequence(){
    sequenceLength = -1;
}

Sequence::Sequence(size_t length) :
    sequenceLength(length) {

}

size_t Sequence::size() const {
    return sequenceLength;
}