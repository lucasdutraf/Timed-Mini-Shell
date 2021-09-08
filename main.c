#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <errno.h>


double time_difference(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

void parent_handler() {
    int child_status;
    struct timeval start, end;

    gettimeofday(&start, NULL);
    pid_t p = wait(&child_status);
    gettimeofday(&end, NULL);

    printf("> Demorou %0.1lf segundos, retornou %d\n", time_difference(&start , &end), WEXITSTATUS(child_status));
    fflush(stdout);
    // sempre quem tem que imprimir o tempo de execução e o código de retorno é o processo pai
}

void child_handler(const char *path, const char *args) {
    execl(path, path, args, NULL);

    printf("> Erro: %s\n", strerror(errno));
    exit(errno);
}


int main (void) {
    char path[255], args[255];
    struct timeval initial_total_time, final_total_time;

    gettimeofday(&initial_total_time, NULL);

    while (scanf("%s %[^\n]", path, args) == 2) { //verificando se o scanf retornou 2 valores
        pid_t pid = fork();
        if (pid == 0) { // child
            child_handler(path, args);
        }
        else if (pid > 0) { // parent
            parent_handler();
        }
    }

    gettimeofday(&final_total_time, NULL);

    printf(">> O tempo total foi de %0.1lf segundos\n", time_difference(&initial_total_time , &final_total_time));
    return 0;
}