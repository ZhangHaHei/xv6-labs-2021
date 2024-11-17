#include "kernel/types.h"
#include "user/user.h"

#define READ        0
#define WRITE       1

int
main(int argc, int argvp[]){

    int p[2];
    pipe(p);

    int pid = fork();
    if(pid == 0){
        char buf[10];
        read(p[READ], buf, 4);
        printf("%d: received %s\n",getpid(), buf);
        write(p[WRITE], "pong", 4);
        exit(0);
    }else if(pid > 0){
        int stat;
        write(p[WRITE], "ping", 4);
        wait(&stat);
        char buf[10];
        read(p[READ], buf, 4);
        printf("%d: received %s\n",getpid(), buf);
        exit(0);
    }else{
        fprintf(2, "fork error");
        exit(1);
    }


}