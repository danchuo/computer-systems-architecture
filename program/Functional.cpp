#include "Functional.h"
#include "Random.h"

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

