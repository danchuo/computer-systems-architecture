#include "ProgrammingLanguage.h"
<<<<<<< HEAD
#include <fstream>

ProgrammingLanguage *In(std::ifstream &ifst) {
    auto *language = new ProgrammingLanguage;
    int k;
    ifst >> k >> language->popularity >> language->year_of_creation;

    switch (k) {
        case 1:language->k = ProgrammingLanguage::PROCEDURAL;
            In(language->p, ifst);
            return language;
        case 2:language->k = ProgrammingLanguage::FUNCTIONAL;
            In(language->f, ifst);
            return language;
        case 3:language->k = ProgrammingLanguage::OBJECTORIENTED;
            In(language->o, ifst);
            return language;
        default:return nullptr;
    }
}

ProgrammingLanguage *InRnd() {
    auto *language = new ProgrammingLanguage;
    language->popularity = (rand() % 100) * 0.1 + 1;
    language->year_of_creation = 1920 + (rand() % 100);

    auto k = rand() % 3 + 1;
    switch (k) {
        case 1:language->k = ProgrammingLanguage::PROCEDURAL;
            InRnd(language->p);
            return language;
        case 2:language->k = ProgrammingLanguage::FUNCTIONAL;
            InRnd(language->f);
            return language;
        case 3:language->k = ProgrammingLanguage::OBJECTORIENTED;
            InRnd(language->o);
            return language;
        default:return 0;
    }
}

void Out(ProgrammingLanguage &l, std::ofstream &ofst) {
    bool is_language_correct = true;
    switch (l.k) {
        case ProgrammingLanguage::PROCEDURAL:Out(l.p, ofst);
            break;
        case ProgrammingLanguage::FUNCTIONAL:Out(l.f, ofst);
            break;
        case ProgrammingLanguage::OBJECTORIENTED:Out(l.o, ofst);
            break;
        default:is_language_correct = false;
            ofst << "Incorrect language!" << '\n';
    }

    if (is_language_correct) {
        ofst << ". Popularity = " << l.popularity
             << ". Year of creation = " << l.year_of_creation
             << ". GeneralFunction = " << GeneralFunction(l) << "\n";
    }
=======
#include "Procedural.h"
#include "Functional.h"
#include "Random.h"
#include "ObjectOriented.h"

ProgrammingLanguage *ProgrammingLanguage::StaticIn(FILE *fptr) {
    int k;
    double popularity;
    int year_of_creation;
    fscanf(fptr, "%d", &k);
    fscanf(fptr, "%lf", &popularity);
    fscanf(fptr, "%d", &year_of_creation);
    ProgrammingLanguage *language = nullptr;
    switch (k) {
        case 1: {
            int are_abstract_types_present;
            fscanf(fptr, "%d", &are_abstract_types_present);
            language = new Procedural(popularity, year_of_creation, are_abstract_types_present);
        }
            break;
        case 2: {
            int t;
            fscanf(fptr, "%d", &t);
            int is_lazy_calculations_support;
            fscanf(fptr, "%d", &is_lazy_calculations_support);
            language = new Functional(popularity,
                                      year_of_creation,
                                      (Functional::typification) t,
                                      is_lazy_calculations_support);
        }
            break;
        case 3: {
            int in;
            fscanf(fptr, "%d", &in);
            language = new ObjectOriented(popularity,
                                          year_of_creation, (ObjectOriented::inheritance) in);
        }
            break;
    }

    if (language == nullptr) {
        language = StaticInRnd();
    }

    return language;
}

ProgrammingLanguage *ProgrammingLanguage::StaticInRnd() {
    auto k = (Random::Random2000() % 3) + 1;
    double popularity = (Random::Random2000() % 100) * 0.1 + 1;
    int year_of_creation = 1920 + (Random::Random2000() % 100);
    switch (k) {
        case 1:return new Procedural(popularity, year_of_creation, (bool) (Random::Random2000() % 2));
        case 2:
            return new Functional(popularity,
                                  year_of_creation,
                                  (Functional::typification) ((Random::Random2000() % 2) + 1),
                                  (bool) (Random::Random2000() % 2));
        default:
            return new ObjectOriented(popularity,
                                      year_of_creation,
                                      (ObjectOriented::inheritance) ((Random::Random2000() % 3) + 1));
    }
}

void ProgrammingLanguage::Out(FILE *fptr) {
    fprintf(fptr,
            "%s%.3lf%s%d%s%.3lf%s",
            ". Popularity = ",
            popularity,
            ". Year of creation = ",
            year_of_creation,
            ". GeneralFunction = ",
            GeneralFunction(), "\n");
>>>>>>> task2/main
}

//------------------------------------------------------------------------------
// В восьмом варианте общая функция выглядит так, будто скопирована из седьмого,
// поэтому буду делить год создания на популярность языка (т.к. не понял, о каком 
// "названии" речь). Ещё можно заметить по 7 варианту, что общая функция не зависит от 
// вида особенностей альтернативы, значит можно обобщить реализацию общей функции, что,
// конечно, упрощает задачу вывода. Я предполагаю, что так и было задумано, т.к. эти
<<<<<<< HEAD
// варианты все чем-то отличаются, и в этот раз мне просто повезло чуть больше.
double GeneralFunction(ProgrammingLanguage &l) {
    return (l.year_of_creation / l.popularity);
=======
// варианты все чем-то отличаются, и в мне просто повезло чуть больше.
double ProgrammingLanguage::GeneralFunction() const {
    return (year_of_creation / popularity);
>>>>>>> task2/main
}
