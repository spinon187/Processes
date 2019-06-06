// Write a program that forks a child and creates a shared pipe
// between the parent and child processes. Have the child write 
// the three messages to the parent and have the parent print out 
// the messages. 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 16

char* msg1 = "hello world #1";
char* msg2 = "hello world #2";
char* msg3 = "hello world #3";

int main(void)
{
    // Your code here
    char buffer[MSGSIZE];
    int p[2];

    if (pipe(p) < 0) {
        fprintf(stderr, "pipe failed\n");
        exit(2);
    }

    pid_t rc = fork();
    if (rc == 0){
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
        exit(1);
    }
    else {
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            close(p[1]);
            while (read(p[0], buffer, MSGSIZE) > 0){
                printf("%s\n", buffer);
            }
        }
    }
    
    return 0;
}
