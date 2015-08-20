#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>

//static int* shared_int = 0;
int main(void)
{
    int status; //variavel auxiliar
    pid_t pid;
    int stat_loc, options = 0;
    int segmento = shmget (IPC_PRIVATE, sizeof(int), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    int* shared_int = (int*) shmat (segmento, 0, 0);
    *shared_int = 1;
    printf("At parent shared INT: %d\n\n", *shared_int);
    pid = fork();

    if (pid == 0) {
        //O código aqui dentro será executado no processo filho
        *shared_int = 5;
        printf("child pid: %d\n", getpid());
        printf("value at child: %d\n\n", *shared_int);
        return 0;
    } else {
        pid = waitpid(pid, &stat_loc, options);
        printf("parent End\n\n");
    }

    // libera a memória compartilhada do processo
    shmdt (shared_int);
    // libera a memória compartilhada
    shmctl (segmento, IPC_RMID, 0);

    return 0;
}
