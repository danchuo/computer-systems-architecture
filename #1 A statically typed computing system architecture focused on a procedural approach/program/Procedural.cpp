#include "Procedural.h"
#include "Random.h"

void In(Procedural &p, std::ifstream &ifst) {
    ifst >> p.are_abstract_types_present;
}

void InRnd(Procedural &p) {
    p.are_abstract_types_present = (bool)(Random() % 2);
}

void Out(Procedural &p, std::ofstream &ofst) {
    ofst << "It is Procedural: are abstract types present = "
         << (p.are_abstract_types_present ? "true" : "false");
}

