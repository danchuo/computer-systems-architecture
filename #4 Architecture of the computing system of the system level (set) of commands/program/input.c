//------------------------------------------------------------------------------
// input.c - единица компиляции, вбирающая в себя все функции ввода данных
//------------------------------------------------------------------------------

#include <stdio.h>

#include "extdata.h"

void InProcedural(void *p, FILE *ifst) {
	char str [80];
    fscanf(ifst, "%d%d%s", (int*)p, (int*)(p+doubleSize), str);
	*(int*)(p+intSize+doubleSize) = str[0] == 'T';
}

void InFunctional(void *f, FILE *ifst) {
	char str [80];
    fscanf(ifst, "%d%d%d%s", (int*)f, (int*)(f+doubleSize), (int*)(f+doubleSize+intSize), str);
	*(int*)(f+2*intSize+doubleSize) = str[0] == 'T';
}

void InObjectOriented(void *o, FILE *ifst) {
    fscanf(ifst, "%d%d%d", (int*)o, (int*)(o+doubleSize), (int*)(o+intSize+doubleSize));
}

// Ввод параметров обобщенной фигуры из файла
int InLanguage(void *l, FILE *ifst) {
    //int k;
    //fscanf(ifst, "%d", &k);
	char str [80];
    fscanf(ifst, "%s", str);
    switch(str[0]) {
        case 'p':
            *((int*)l) = PROCEDURAL;
            InProcedural(l+intSize, ifst);
            return 1;
        case 'f':
            *((int*)l) = FUNCTIONAL;
            InFunctional(l+intSize, ifst);
            return 1;
	    case 'o':
            *((int*)l) = OBJECTORIENTED;
            InObjectOriented(l+intSize, ifst);
            return 1;
        default:
            return 0;
    }
}

// Ввод содержимого контейнера из указанного файла
void InContainer(void *c, int *len, FILE *ifst) {
    void *tmp = c;
	fscanf(ifst, "%d", &(*len));
    for (int i = 0; i < *len; ++i) {
        InLanguage(tmp, ifst);
		tmp = tmp + languageSize;
    }
}
