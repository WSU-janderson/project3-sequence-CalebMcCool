#ifndef Sequence_h
#define Sequence_h
#include <cstdlib>
#include <string>

class Sequence{
private:
    int sequenceLength;


public:
    Sequence();
    Sequence(size_t length);

    size_t size() const;

};

#endif Sequence_h