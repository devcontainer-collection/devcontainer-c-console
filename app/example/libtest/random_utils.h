#pragma once

#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

    int random_int(int min, int max);
    char *random_string(size_t length);

#ifdef __cplusplus
}
#endif
