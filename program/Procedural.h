#ifndef __Procedural__
#define __Procedural__

#include <fstream>
struct Procedural {
  bool are_abstract_types_present;
};

void In(Procedural &p, std::ifstream &ifst);

void InRnd(Procedural &p);

void Out(Procedural &p, std::ofstream &ofst);

#endif 
