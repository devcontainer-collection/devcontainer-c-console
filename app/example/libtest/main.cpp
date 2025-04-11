#include <stdio.h>
#include "random_utils.h"

int main()
{
    int value = random_int(1, 100);
    const char *str = random_string(10);

    printf("Random Int: %d\n", value);
    printf("Random String: %s\n", str);

    return 0;
}
