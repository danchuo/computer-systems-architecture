#ifndef __ProgrammingLanguage__
#define __ProgrammingLanguage__

<<<<<<< HEAD
#include "Procedural.h"
#include "Functional.h"
#include "ObjectOriented.h"

struct ProgrammingLanguage {
  enum key { PROCEDURAL, FUNCTIONAL, OBJECTORIENTED };
  key k;
  double popularity;
  int year_of_creation;
  union {
    Procedural p;
    Functional f;
    ObjectOriented o;
  };
};

ProgrammingLanguage *In(std::ifstream &ifdt);

ProgrammingLanguage *InRnd();

void Out(ProgrammingLanguage &l, std::ofstream &ofst);

double GeneralFunction(ProgrammingLanguage &l);

=======
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
>>>>>>> task2/main
#endif
