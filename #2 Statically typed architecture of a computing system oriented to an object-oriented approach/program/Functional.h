#ifndef __Functional__
#define __Functional__

<<<<<<< HEAD
#include <fstream>

struct Functional {
  enum typification { STRICT, DYNAMIC };
  typification t;
  bool is_lazy_calculations_support;
};

void In(Functional &f, std::ifstream &ifst);

void InRnd(Functional &f);

void Out(Functional &f, std::ofstream &ofst);

=======
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
>>>>>>> task2/main
#endif 
