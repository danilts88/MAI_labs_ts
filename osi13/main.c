#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>

int main(int argc, char*argv[]) {

    if (argc != 3) {
        printf("Enter the file name\n");
        return 1;
    }

    FILE* in;
    FILE* out;
    if (!(in = fopen(argv[1], "rb"))) {
        printf("The file could not be opened\n");
        return 0;
    }

    int i = 0;
    int lenBeforeDot = 0;
    char* format = (char*)malloc(sizeof(char) * 6);
    while(argv[1][i] != '.') {
        i++;
    }
    lenBeforeDot = i;
    int m = 0;
    if (argv[1][i] == '.') {
        while(argv[1][i]) {
            format[m] = argv[1][i];
            i++;
            m++;
        }
    }
    format[m] = '\0';

    if ( !(out = fopen(argv[2], "wb"))) {
        printf("The result file could not be created\n");
        fclose(in);
        return 0;
    }
    fseek(in, 0, SEEK_END);
    long size = ftell(in);

    char* buff = (char*)malloc(sizeof(char) * size);
    if (!buff) {
        printf("Failed to allocate memory\n");
        fclose(in);
        fclose(out);
        return 0;
    }

    fseek(in, 0, SEEK_SET);
    fread(buff, sizeof(char), size, in);
    fwrite(buff, sizeof(char), size, out);

    free(buff);
    fclose(in);
    fclose(out);
    return 0;
}
