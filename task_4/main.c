#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3)
    {
        printf("Invalid args count!\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");

    if (f == NULL)
    {
        printf("Invalid file name!\n");
    }

    int n = atoi(argv[2]);

    int counter = 0;
    char ch;
    while((ch = fgetc(f)) != EOF) {
        fputc(ch, stdout);
        if (n !=0)
        {
            if (ch == '\n')
                counter++;
            if (counter == n)
            {
                fgetc(stdin);
                counter = 0;
            }
        }
    }

    if (fclose(f) == EOF) {
        printf("Error when closing file\n");
        return 1;
    }

    return 0;
}