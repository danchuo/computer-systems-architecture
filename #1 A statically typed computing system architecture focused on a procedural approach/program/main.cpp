#include <fstream> // fstream, к сожалению, оставил вывода и ввода.
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Container.h"

void errMessage1() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    Container c;
    Init(c);

    if (!strcmp(argv[1], "-f")) {
        std::ifstream ifst(argv[2]);
        In(c, ifst);
    } else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect number of figures =  %d %s",
                   size,
                   ". Set 0 < number <= 10000\n");
            return 3;
        }

        srand(static_cast<unsigned int>(time(0)));

        InRnd(c, size);
    } else {
        errMessage2();
        return 2;
    }

    std::ofstream ofst1(argv[3]);
    ofst1 << "Filled container:\n";
    Out(c, ofst1);

    QuickSort(c, 0, c.len - 1);
    std::ofstream ofst2(argv[4]);
    ofst2 << "Sorted container:\n";
    Out(c, ofst2);

    Clear(c);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Stop\n");
    printf("Programm took %f seconds to execute \n", cpu_time_used);

    return 0;
}
