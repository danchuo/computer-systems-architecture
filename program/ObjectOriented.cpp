#include "ObjectOriented.h"

void ObjectOriented::Out(FILE *fptr) {
    auto inher = (in == 1 ? "SINGLE" : "MULTIPLE");

    if (in == 3) {
        inher = "INTERFACE";
    }

    fprintf(fptr, "%s%s", "It is ObjectOriented: inheritance = ", inher);
    ProgrammingLanguage::Out(fptr);
}
ObjectOriented::ObjectOriented(double popularity, int year_of_creation, ObjectOriented::inheritance in) {
    this->popularity = popularity;
    this->year_of_creation = year_of_creation;
    this->in = in;
}
