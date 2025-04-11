#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../lib/string_utils/string_utils.h"

int main()
{
    char name[256] = "";

    while (1)
    {
        printf("Enter your name: ");
        fgets(name, sizeof(name), stdin);

        name[strcspn(name, "\n")] = '\0'; // remove newline

        // in-place trim (간단하게)
        char *start = name;
        while (*start && isspace((unsigned char)*start))
            start++;

        char *end = start + strlen(start);
        while (end > start && isspace((unsigned char)*(end - 1)))
            end--;
        *end = '\0';

        if (!is_blank(start))
        {
            // 앞으로 당기기 (trim된 문자열을 name에 다시 복사)
            if (start != name)
                memmove(name, start, end - start + 1);
            break;
        }
    }

    printf("Hello, %s!\n", name);
    return 0;
}
