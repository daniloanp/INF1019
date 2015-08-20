#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int i;
    pid_t pid;
    int stat_loc, options = 0;

    printf("parent pid: %d\n", getpid());
    pid = fork();

    if (pid == 0) {
        //O código aqui dentro será executado no processo filho
        printf("child pid: %d\n", getpid());
    } else {
        pid = waitpid(pid, &stat_loc, options);
        printf("parent End\n\n");
    }

    return 0;
}
