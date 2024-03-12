#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>

int main() {
    printf("ID of the current process: %d\n", getpid());
    printf("ID of the parent process: %d\n", getppid());
    printf("ID of the calling process group: %d\n", getpgrp());
    printf("The real ID of the owner: %d\n", getuid());
    printf("The real ID of the owner's group: %d\n", getgid());
    printf("Effective owner ID: %d\n", geteuid());
    printf("Effective identifier of the owner's group: %d\n", getegid());

}