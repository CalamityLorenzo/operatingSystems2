#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){

printf("hello world, (pid:%d)\n", (int)getpid());
int rc = fork();
if(rc<0){ // failed fork
    fprintf(stderr, "fork failed");
    exit(1);
} else if(rc ==0){
    close(STDOUT_FILENO);
    open("./p4.output", O_CREAT| O_WRONLY | O_TRUNC , S_IRWXU);
    printf("hello, I am child (pid:%d)\n", (int) getpid());
    char* myargs[3];
    myargs[0]=strdup("wc");
    myargs[1]=strdup("p4.c");
    myargs[2]=NULL;
    execvp(myargs[0], myargs);
    printf("This shouldn't print out");
}else{
    int rc_wait = wait(NULL);
    printf("hello I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int)getpid());
}
return 0;

}