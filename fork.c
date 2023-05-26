#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char*argv[]){
    printf("hello, world (p:%d)\n", (int)getpid());

    int rc = fork();
    if (rc<0){ // fork failed
        fprintf(stderr, "fork failed");
        exit(1);
    }else if(rc==0){ // Child (new process)
        printf("hello, I am child (p:%d)\n", (int) getpid());
    }else{ // Parent (the one that actually started this process)
        int rc_wait = wait(NULL);
        printf("I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int)getpid());
    }
    return 0;
}