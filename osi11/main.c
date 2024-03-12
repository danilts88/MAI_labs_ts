#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>

int main(int argc, char*argv[]) {

    if (argc != 2) {
        printf("Enter the file name\n");
        return 1;
    }

    FILE* in;
    if (!(in = fopen(argv[1], "wb+"))) {
        printf("The file could not be opened\n");
        return 0;
    }

    char bytes[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    fwrite(bytes, sizeof(bytes), sizeof(bytes)/sizeof(char), in);

    printf("Byte-by-byte content output to the console:\n");
    int size = sizeof(bytes)/sizeof(char);
    fseek(in, 0, SEEK_SET);
    char* buffer = (char*)malloc(sizeof(char) * size);

    if (!buffer) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    fread(buffer, sizeof(char), sizeof(bytes)/sizeof(char), in);
    for (int i = 0; i < size; i++) {
        printf("%d\n", buffer[i]);
        printf("_flags: %d ", in->_flag);
        printf("_fileno: %d ", in->_file);
        printf("\n");
    }
    //struct _IO_FILE-

    printf("\n");

    fclose(in);
    free(buffer);

    FILE* inForRead = fopen(argv[1], "rb");
    printf("After moving the pointer to 3:\n");
    if (fseek(inForRead, 3, SEEK_SET) != 0) {
        printf("Error when moving the pointer\n");
        fclose(inForRead);
        return 0;
    }
    char buff[4];
    size_t count = fread(buff, sizeof(char), 4, inForRead);
    if (count != 4) {
        printf("Error reading from a file\n");
        fclose(inForRead);
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        printf("%d ", buff[i]);
    }
    printf("\n");
    fclose(inForRead);
    return 0;
}