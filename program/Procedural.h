#ifndef __Procedural__
#define __Procedural__

#include "ProgrammingLanguage.h"

class Procedural : public ProgrammingLanguage {
public:
    Procedural(double popularity, int year_of_creation, bool are_abstract_types_present);
    virtual void Out(FILE *fptr);
private:
    bool are_abstract_types_present;
};

#endif 
