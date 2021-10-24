#ifndef __Functional__
#define __Functional__

#include "ProgrammingLanguage.h"

class Functional : public ProgrammingLanguage {
public:
    enum typification { STRICT, DYNAMIC };
    Functional(double popularity, int year_of_creation, typification t, bool is_lazy_calculations_support);
    virtual void Out(FILE *fptr);
private:
    typification t;
    bool is_lazy_calculations_support;
};
#endif 
