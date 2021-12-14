#include "ProgrammingLanguage.h"
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
}

//------------------------------------------------------------------------------
// В восьмом варианте общая функция выглядит так, будто скопирована из седьмого,
// поэтому буду делить год создания на популярность языка (т.к. не понял, о каком 
// "названии" речь). Ещё можно заметить по 7 варианту, что общая функция не зависит от 
// вида особенностей альтернативы, значит можно обобщить реализацию общей функции, что,
// конечно, упрощает задачу вывода. Я предполагаю, что так и было задумано, т.к. эти
// варианты все чем-то отличаются, и в этот раз мне просто повезло чуть больше.
double GeneralFunction(ProgrammingLanguage &l) {
    return (l.year_of_creation / l.popularity);
}
