#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2)
    {
        printf("Invalid args count!\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "w");

    if (f == NULL)
    {
        printf("Invalid file name!\n");
    }

    char ch;
    printf("Press CTRL+D to exit\n");

    while ((ch = getc(stdin)) != EOF) {  
        if (fputc(ch, f) == EOF) {
            printf("Error writing in file\n");
            break;
        }
    }

    if (fclose(f) == EOF) {
        printf("Error when closing file\n");
        return 1;
    }

    return 0;
}