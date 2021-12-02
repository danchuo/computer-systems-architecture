//------------------------------------------------------------------------------
// output.c - единица компиляции, вбирающая в себя все функции вывода данных
//------------------------------------------------------------------------------

#include <stdio.h>

#include "extdata.h"

// Вычисление общей функции
double GeneralFunction(void *l);
// Вывод параметров проце в файл
void OutProcedural(void *p, FILE *ofst) {
    fprintf(ofst,
            "%s%s",
            "It is Procedural: are abstract types present = ",
            (*((int*)(p + intSize + doubleSize)) == 1 ? "true" : "false"));
}

void OutFunctional(void *f, FILE *ofst) {
    fprintf(ofst,
            "%s%s%s%s",
            "It is Functional: typification = ",
            (*((int*)(f + intSize + doubleSize)) == 1 ? "STRICT" : "DYNAMIC"),
            ", is lazy calculations support = ",
            (*((int*)(f + 2*intSize + doubleSize)) == 1 ? "true" : "false"));
}

void OutObjectOriented(void *o, FILE *ofst) {
    fprintf(ofst, "%s%s", "It is ObjectOriented: inheritance = ", 
	(*((int*)(o + intSize + doubleSize)) == 1 ? "SINGLE" : 
	(*((int*)(o + intSize + doubleSize)) == 2 ? "MULTIPLE" : "INTERFACE")));
}

void OutLanguage(void *l, FILE *ofst) {
    int k = *((int*)l);
    if(k == PROCEDURAL) {
        OutProcedural(l+intSize, ofst);
    }
    else if(k == FUNCTIONAL) {
        OutFunctional(l+intSize, ofst);
    }
    else if (k == OBJECTORIENTED) {
        OutObjectOriented(l+intSize, ofst);
    }
	fprintf(ofst,
            "%s%d%s%d%s%.2f%s",
            ". Popularity = ",
            *((int*)(l+intSize)),
            ". Year of creation = ",
            *((int*)(l+doubleSize+intSize)),
            ". GeneralFunction = ",
            GeneralFunction(l), "\n");
}

// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *ofst) {
    void *tmp = c;
    fprintf(ofst, "Container contains %d elements.\n", len);
    for(int i = 0; i < len; i++) {
        fprintf(ofst, "%d: ", i+1);
        OutLanguage(tmp, ofst);
        tmp = tmp + languageSize;
    }
}
