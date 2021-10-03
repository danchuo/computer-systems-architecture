#ifndef __ObjectOriented__
#define __ObjectOriented__

#include <fstream>

struct ObjectOriented {
  enum inheritance { SINGLE, MULTIPLE, INTERFACE };
  inheritance in;
};

void In(ObjectOriented &o, std::ifstream &ifst);

void InRnd(ObjectOriented &o);

void Out(ObjectOriented &o, std::ofstream &ofst);

#endif 
