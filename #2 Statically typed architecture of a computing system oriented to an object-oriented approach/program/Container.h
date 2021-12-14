#ifndef __Container__
#define __Container__

<<<<<<< HEAD
#include "ProgrammingLanguage.h"

struct Container {
  enum { max_length = 10000 };
  int len;
  ProgrammingLanguage *cont[max_length];
};

void Init(Container &c);

void Clear(Container &c);

void In(Container &c, std::ifstream &ifst);

void InRnd(Container &c, int size);

void Out(Container &c, std::ofstream &ofst);

void QuickSort(Container &c, int low, int high);

int Partition(Container &c, int low, int high);

void Swap(ProgrammingLanguage *a, ProgrammingLanguage *b);
=======
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
>>>>>>> task2/main

#endif
