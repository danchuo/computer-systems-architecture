#ifndef __ObjectOriented__
#define __ObjectOriented__

#include "ProgrammingLanguage.h"

class ObjectOriented : public ProgrammingLanguage {
public:
    enum inheritance { SINGLE, MULTIPLE, INTERFACE };
    ObjectOriented(double popularity, int year_of_creation, inheritance in);
    virtual void Out(FILE *fptr);
private:
    inheritance in;
};
#endif 
