#ifndef __Container__
#define __Container__

#include <stdio.h>
#include "ProgrammingLanguage.h"

class Container {
public:
    void Init();

    void Clear();

    void In(FILE *fptr);

    void InRnd(int size);

    void Out(FILE *fptr);

    void QuickSort(int low, int high);

    int Partition(int low, int high);

    static void Swap(ProgrammingLanguage **a, ProgrammingLanguage **b);
    int len;
private:
    enum { max_length = 10000 };

    ProgrammingLanguage *cont[max_length];
};

#endif
