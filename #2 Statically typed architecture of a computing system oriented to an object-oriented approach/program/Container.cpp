#include "Container.h"

<<<<<<< HEAD
void Init(Container &c) {
    c.len = 0;
}

void Clear(Container &c) {
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

void In(Container &c, std::ifstream &ifst) {
    while (!ifst.eof()) {
        if ((c.cont[c.len] = In(ifst)) != nullptr) {
            c.len++;
        }
    }
}

void InRnd(Container &c, int size) {
    while (c.len < size) {
        if ((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
=======
void Container::Init() {
    len = 0;
}

void Container::Clear() {
    for (int i = 0; i < len; i++) {
        delete cont[i];
    }
    len = 0;
}

void Container::In(FILE *fptr) {
    fscanf(fptr, "%d", &len);
    for (int i = 0; i < len; ++i) {
        (cont[i] = ProgrammingLanguage::StaticIn(fptr));
    }
}

void Container::InRnd(int size) {
    while (len < size) {
        if ((cont[len] = ProgrammingLanguage::StaticInRnd()) != nullptr) {
            len++;
>>>>>>> task2/main
        }
    }
}

<<<<<<< HEAD
void Out(Container &c, std::ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements." << '\n';
    for (int i = 0; i < c.len; i++) {
        ofst << (i + 1) << ": ";
        Out(*(c.cont[i]), ofst);
    }
}

void QuickSort(Container &c, int low, int high) {
    if (low < high) {
        int pivot = Partition(c, low, high);

        QuickSort(c, low, pivot - 1);
        QuickSort(c, pivot + 1, high);
    }
}

int Partition(Container &c, int low, int high) {
    ProgrammingLanguage pivot = *c.cont[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (GeneralFunction(*c.cont[j]) < GeneralFunction(pivot)) {
            i++;
            Swap(c.cont[i], c.cont[j]);
        }
    }
    Swap(c.cont[i + 1], c.cont[high]);
    return (i + 1);
}

void Swap(ProgrammingLanguage *a, ProgrammingLanguage *b) {
    ProgrammingLanguage t = *a;
=======
void Container::Out(FILE *fptr) {
    fprintf(fptr, "%s%d%s", "Container contains ", len, " elements.\n");

    for (int i = 0; i < len; i++) {
        fprintf(fptr, "%d%s", (i + 1), ": ");
        cont[i]->Out(fptr);
    }
}

void Container::QuickSort(int low, int high) {
    if (low < high) {
        int pivot = Partition(low, high);

        QuickSort(low, pivot - 1);
        QuickSort(pivot + 1, high);
    }
}

int Container::Partition(int low, int high) {
    ProgrammingLanguage pivot = *cont[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (cont[j]->GeneralFunction() < pivot.GeneralFunction()) {
            i++;
            Swap(&cont[i], &cont[j]);
        }
    }
    Swap(&cont[i + 1], &cont[high]);
    return (i + 1);
}

void Container::Swap(ProgrammingLanguage **a, ProgrammingLanguage **b) {
    ProgrammingLanguage *t = *a;
>>>>>>> task2/main
    *a = *b;
    *b = t;
}
