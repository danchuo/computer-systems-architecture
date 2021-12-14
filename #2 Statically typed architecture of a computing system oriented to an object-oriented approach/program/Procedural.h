#ifndef __Procedural__
#define __Procedural__

<<<<<<< HEAD
#include <fstream>
struct Procedural {
  bool are_abstract_types_present;
};

void In(Procedural &p, std::ifstream &ifst);

void InRnd(Procedural &p);

void Out(Procedural &p, std::ofstream &ofst);

=======
#include "ProgrammingLanguage.h"

class Procedural : public ProgrammingLanguage {
public:
    Procedural(double popularity, int year_of_creation, bool are_abstract_types_present);
    virtual void Out(FILE *fptr);
private:
    bool are_abstract_types_present;
};

>>>>>>> task2/main
#endif 
