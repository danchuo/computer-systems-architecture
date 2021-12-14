#ifndef __ObjectOriented__
#define __ObjectOriented__

<<<<<<< HEAD
#include <fstream>

struct ObjectOriented {
  enum inheritance { SINGLE, MULTIPLE, INTERFACE };
  inheritance in;
};

void In(ObjectOriented &o, std::ifstream &ifst);

void InRnd(ObjectOriented &o);

void Out(ObjectOriented &o, std::ofstream &ofst);

=======
#include "ProgrammingLanguage.h"

class ObjectOriented : public ProgrammingLanguage {
public:
    enum inheritance { SINGLE, MULTIPLE, INTERFACE };
    ObjectOriented(double popularity, int year_of_creation, inheritance in);
    virtual void Out(FILE *fptr);
private:
    inheritance in;
};
>>>>>>> task2/main
#endif 
