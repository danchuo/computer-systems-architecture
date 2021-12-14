#include "Container.h"

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
        }
    }
}

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
    *a = *b;
    *b = t;
}
