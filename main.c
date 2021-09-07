#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

int main (void) {

    char path[255], args[255];

    while (scanf("%s %s", path, args) != EOF) {
        printf("%s %s\n", path, args);
    }

    return 0;
}