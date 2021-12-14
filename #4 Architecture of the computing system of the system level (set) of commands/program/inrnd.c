//------------------------------------------------------------------------------
// inrnd.c - единица компиляции, вбирающая функции генерации случайных данных
//------------------------------------------------------------------------------

#include <stdlib.h>

#include "extdata.h"

// rnd.c - содержит генератор случайных чисел в диапазоне от 1 до 2000
int Random() {
    return rand() % 2000 + 1;
}

// Случайный ввод параметров прямоугольника
void InRndProcedural(void *p) {
    int x = (Random() % 100) + 1;
    *((int*)p) = x;
    int y = (Random() % 100) + 1920;
    *((int*)(p+doubleSize)) = y;
	int z = Random() % 2;
	*((int*)(p+doubleSize+intSize)) = z;
}

void InRndFunctional(void *f) {
    int x = (Random() % 100) + 1;
    *((int*)f) = x;
    int y = (Random() % 100) + 1920;
    *((int*)(f+doubleSize)) = y;
	int z = Random() % 2 + 1;
	*((int*)(f+doubleSize+intSize)) = z;
    int w = Random() % 2;
	*((int*)(f+doubleSize+2*intSize)) = w;
}

void InRndObjectOriented(void *o) {
    int x = (Random() % 100) + 1;
    *((int*)o) = x;
    int y = (Random() % 100) + 1920;
    *((int*)(o+doubleSize)) = y;
	int z = (Random() % 3) + 1;
	*((int*)(o+doubleSize+intSize)) = z;
}

// Случайный ввод обобщенной фигуры
int InRndLanguage(void *l) {
    int k = rand() % 3 + 1;
    switch(k) {
        case 1:
            *((int*)l) = PROCEDURAL;
            InRndProcedural(l+intSize);
            return 1;
        case 2:
            *((int*)l) = FUNCTIONAL;
            InRndFunctional(l+intSize);
            return 1;
        case 3:
            *((int*)l) = OBJECTORIENTED;
            InRndObjectOriented(l+intSize);
            return 1;
        default:
            return 0;
    }
}

// Случайный ввод содержимого контейнера
void InRndContainer(void *c, int *len, int size) {
    void *tmp = c;
    while(*len < size) {
        if(InRndLanguage(tmp)) {
            tmp = tmp + languageSize;
            (*len)++;
        }
    }
}
