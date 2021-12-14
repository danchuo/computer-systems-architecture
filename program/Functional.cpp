#include "Functional.h"
#include "Random.h"

void In(Functional &f, std::ifstream &ifst) {
    int input;
    ifst >> input >> f.is_lazy_calculations_support;
    f.t = (Functional::typification)(input);
}

void InRnd(Functional &f) {
    f.is_lazy_calculations_support = (bool)(Random() % 2);
    f.t = (Functional::typification)((Random() % 2) + 1);
}

void Out(Functional &f, std::ofstream &ofst) {
    ofst << "It is Functional: typification = "
         << (f.t == 1 ? "STRICT" : "DYNAMIC")
         << ", is lazy calculations support = " 
         << (f.is_lazy_calculations_support ? "true" : "false");
}


