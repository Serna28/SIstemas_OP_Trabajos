#include <stdio.h>
#include <string.h>

char *fgets(char *str, int n, FILE *stream);

int main(void)
{
    char name[40];
    printf("What's your name? ");
    if (fgets(name, 40, stdin))
    {
        name[strcspn(name, "\n")] = 0;
        printf("Hello %s!\n", name);
    }
}