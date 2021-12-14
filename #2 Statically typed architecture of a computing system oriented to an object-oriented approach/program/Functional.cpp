#include "Functional.h"
#include "Random.h"

<<<<<<< HEAD
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


=======
void Functional::Out(FILE *fptr) {
    fprintf(fptr,
            "%s%s%s%s",
            "It is Functional: typification = ",
            (t == 1 ? "STRICT" : "DYNAMIC"),
            ", is lazy calculations support = ",
            (is_lazy_calculations_support ? "true" : "false"));
    ProgrammingLanguage::Out(fptr);
}
Functional::Functional(double popularity, int year_of_creation, typification t, bool is_lazy_calculations_support) {
    this->popularity = popularity;
    this->year_of_creation = year_of_creation;
    this->t = t;
    this->is_lazy_calculations_support = is_lazy_calculations_support;
}

>>>>>>> task2/main
