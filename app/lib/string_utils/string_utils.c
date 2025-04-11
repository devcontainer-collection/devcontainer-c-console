// Define _GNU_SOURCE to enable GNU-specific extensions, such as strdup.
#define _GNU_SOURCE

#include "string_utils.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// remove leading and trailing whitespace from a string
char *trim(const char *str)
{
    if (str == NULL)
        return NULL;

    const char *first = str;
    while (*first && isspace((unsigned char)*first))
    {
        first++;
    }

    if (*first == '\0')
        return strdup(""); // all spaces

    const char *last = str + strlen(str) - 1;
    while (last > first && isspace((unsigned char)*last))
    {
        last--;
    }

    size_t length = last - first + 1;
    char *trimmed = (char *)malloc(length + 1);
    if (trimmed)
    {
        strncpy(trimmed, first, length);
        trimmed[length] = '\0';
    }
    return trimmed;
}

// check if string is empty or contains only whitespace
int is_blank(const char *str)
{
    if (str == NULL)
        return 1;

    while (*str)
    {
        if (!isspace((unsigned char)*str))
            return 0;
        str++;
    }
    return 1;
}
