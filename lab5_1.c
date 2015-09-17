#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static int fd[2];

int parent() {
    char buf;
    int size = 0;
    close(fd[1]);
    wait(NULL); // wait child
    while (read(fd[0], &buf, 1) > 0) {
        printf("%c",buf);
        size++;
    }
    printf("\n\tPai leu %d bytes\n", size);
    close(fd[0]);
    
    return 0;
}

int child(char *argv[]) {
    close(fd[0]);
    write(fd[1], argv[1], strlen(argv[1]));
    close(fd[1]);
    _exit(EXIT_SUCCESS);
    return 0;
}




int main(int argc, char *argv[]) {
    pid_t pid;
    pipe(fd);
    pid = fork();

    
    
    if (pid == 0) {
       return child(argv);
    } else {
        return parent();
    }
    
    return 0;
}
