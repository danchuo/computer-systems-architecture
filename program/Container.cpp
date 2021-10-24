#include "Container.h"

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
        }
    }
}

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
    *a = *b;
    *b = t;
}
