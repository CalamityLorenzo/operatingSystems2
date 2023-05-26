#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main (int argc, char* argv[]){
    printf("homework 1\n");
    int x=17;
    
    int rc = fork();
        x=28;
// failed fork
    if(rc<0){
        fprintf(stderr, "failed fork\n");
        exit(1);
    }

// Child process
    if(rc==0){
        printf("I am the child process (%d) x=%d %p\n", getpid(), x, &x);
        x=32;
        printf("I am the child process checking in (%d) x=%d %p\n", getpid(), x, &x);

    }
// parent process
    else{ 
        int rc_wait = wait(NULL);
        printf("I am the parent process x=%d %p\n",x, &x);
    }

}