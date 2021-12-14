#ifndef __Random__
#define __Random__

#include <stdlib.h>

inline auto Random() {
    return rand() % 20 + 1;
}

#endif 
