#ifndef __ProgrammingLanguage__
#define __ProgrammingLanguage__

#include <stdio.h>
class ProgrammingLanguage {
protected:
    double popularity;
    int year_of_creation;
public:
    double GeneralFunction() const;
    static ProgrammingLanguage *StaticIn(FILE *fptr);
    static ProgrammingLanguage *StaticInRnd();
    virtual ~ProgrammingLanguage() {};
    virtual void Out(FILE *fptr);
};
#endif
