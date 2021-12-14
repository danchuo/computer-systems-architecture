#ifndef __Functional__
#define __Functional__

#include <fstream>

struct Functional {
  enum typification { STRICT, DYNAMIC };
  typification t;
  bool is_lazy_calculations_support;
};

void In(Functional &f, std::ifstream &ifst);

void InRnd(Functional &f);

void Out(Functional &f, std::ofstream &ofst);

#endif 
