#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100000
int main()
{
    char string[max];
    char string2[max];
    fgets(string, max, stdin);
    char search[] = {"zelda"};
    int i = 0;
    while (string[i] != '\0')
    {
        string2[i] = tolower(string[i]);
        i++;
    }

    char *ptr = strstr(string2, search);
    if (ptr)
    {
        printf("Link Bolado\n");
    }
    else
    {
        printf("Link Tranquilo\n");
    }
    return 0;
}
