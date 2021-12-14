#include "Procedural.h"
<<<<<<< HEAD
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

=======

void Procedural::Out(FILE *fptr) {
    fprintf(fptr,
            "%s%s",
            "It is Procedural: are abstract types present = ",
            (are_abstract_types_present ? "true" : "false"));
    ProgrammingLanguage::Out(fptr);
}

Procedural::Procedural(double popularity, int year_of_creation, bool are_abstract_types_present)
    : ProgrammingLanguage() {
    this->popularity = popularity;
    this->year_of_creation = year_of_creation;
    this->are_abstract_types_present = are_abstract_types_present;
}
>>>>>>> task2/main
