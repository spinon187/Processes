// Write another program using `fork()`. The child process should print "hello";
// the parent process should print "goodbye". You should ensure that the child
// process always prints first.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here
    pid_t rc = fork();
    if (rc == 0){
        printf("hello\n");
        exit(1);
    }
    else {
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            printf("goodbye\n");
        }
    }
    return 0;
}
