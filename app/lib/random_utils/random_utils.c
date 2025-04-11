#include "random_utils.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

int random_int(int min, int max)
{
    static int initialized = 0;
    if (!initialized)
    {
        srand((unsigned int)time(NULL));
        initialized = 1;
    }
    return min + rand() % (max - min + 1);
}

char *random_string(size_t length)
{
    static const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    size_t charset_size = sizeof(charset) - 1;

    char *result = (char *)malloc(length + 1);
    if (!result)
    {
        return NULL; // Handle memory allocation failure
    }

    for (size_t i = 0; i < length; ++i)
    {
        result[i] = charset[rand() % charset_size];
    }
    result[length] = '\0'; // Null-terminate the string
    return result;
}
