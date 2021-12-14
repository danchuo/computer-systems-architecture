#include "ObjectOriented.h"
<<<<<<< HEAD
#include "Random.h"
#include <fstream>
using namespace std;

void In(ObjectOriented &o, ifstream &ifst) {
    int input;
    ifst >> input;
    o.in = (ObjectOriented::inheritance) (input);
}

void InRnd(ObjectOriented &o) {
    o.in = (ObjectOriented::inheritance) ((Random() % 3) + 1);
}

void Out(ObjectOriented &o, ofstream &ofst) {
    auto inher = (o.in == 1 ? "SINGLE" : "MULTIPLE");

    if (o.in == 3) {
        inher = "INTERFACE";
    }

    ofst << "It is ObjectOriented: inheritance = "
         << inher;
=======

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
>>>>>>> task2/main
}
