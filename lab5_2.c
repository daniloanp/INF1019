#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

static int fd[2];

/*
int parent(FILE *f) {
    char buf;
    int size = 0;
    close(fd[1]);
    wait(NULL); // wait child
    while (read(fd[0], &buf, 1) > 0) {
        fprintf(f, "%c", buf);
        size++;
    }
    close(fd[0]);
    fclose(f);
    return 0;
}

int child(FILE *f) {
    int c = 0;
    close(fd[0]);
    while ((c = fgetc(f)) != EOF) {
        c = (char) c;
        write(fd[1], &c, 1);        
    }
    
    close(fd[1]);
    _exit(EXIT_SUCCESS);
    fclose(f);
    return 0;
}
*/




int main(int argc, char *argv[]) {
    pid_t pid;
  //  pipe(fd);
//    pid = fork();
    int in, out;
    
    if (argc < 3) {
        printf ("Please, enter two args!!");
    }
    
    printf("in:%s\n", argv[1]);
    printf("out:%s\n", argv[2]);
    
    in = open(argv[1],O_RDWR|O_CREAT|O_TRUNC,0666);
    out = open(argv[2],O_RDWR|O_CREAT|O_TRUNC,0666);
    
    close(0);
    dup(in);
    
    close(1);
    dup(out);
    
    // Testing
    printf("Scanning...\n");
    scanf("%d", &in);
    scanf("%c", &out);
    
    printf("Integer:%d\n", in);
    printf("Char:%c\n", out);
    
    
    
    return 0;
}
