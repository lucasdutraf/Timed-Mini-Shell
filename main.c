#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/time.h>

float time_difference(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) + 1e-6*(end->tv_usec - start->tv_usec);
}


int main (void) {

    char path[255], args[255];
    struct timeval initial_total_time, final_total_time;
    gettimeofday(&initial_total_time, NULL);
    while (scanf("%s %s", path, args) != EOF) {
        printf("%s %s\n", path, args);
    }
    gettimeofday(&final_total_time, NULL);
    printf(">> O tempo total foi de %f segundos\n", time_difference(&initial_total_time , &final_total_time));
    return 0;
}