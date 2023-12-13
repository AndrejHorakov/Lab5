#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3)
    {
        printf("Invalid args count!\n");
        printf(" <File from> <File to>\n");
        return 1;
    }

    FILE *ffrom = fopen(argv[1], "r");
    FILE *fto = fopen(argv[2], "w");

    if (ffrom == NULL)
    {
        printf("Invalid file from name!\n");
    }

    if (fto == NULL)
    {
        printf("Invalid file to name!\n");
    }

    char ch;
     while ((ch = fgetc(ffrom)) != EOF) {
        fputc(ch, fto);
    }

    if (fclose(ffrom) == EOF || fclose(fto)) {
        printf("Error when closing file\n");
        return 1;
    }

    return 0;
}