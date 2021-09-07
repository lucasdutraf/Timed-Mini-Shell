#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <errno.h>


float time_difference(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}

void parent_handler() {
    int child_status;
    pid_t p = wait(&child_status);
    printf("filho %d terminou com %d, também vou\n", p, WEXITSTATUS(child_status));

}

void child_handler(const char *path, const char *args) {
    struct timeval start, end;

    gettimeofday(&start, NULL);
    int return_code = execl(path, path, args, NULL);
    gettimeofday(&end, NULL);

    if (return_code == -1){
        printf("> Erro: %s\n", strerror(errno));
        _exit(errno);
    }
    printf("> Demorou %0.1f segundos, retornou %d\n", time_difference(&start, &end), return_code);
}


int main (void) {
    char path[255], args[255];
    struct timeval initial_total_time, final_total_time;

    gettimeofday(&initial_total_time, NULL);

    while (scanf("%s %s", path, args) != EOF) {
        pid_t pid = fork();
        if (pid == 0) { // child
            child_handler(path, args);
        }
        else if (pid > 0) { // parent
            parent_handler();
        }
    }

    gettimeofday(&final_total_time, NULL);

    printf(">> O tempo total foi de %0.1f segundos\n", time_difference(&initial_total_time , &final_total_time));
    return 0;
}