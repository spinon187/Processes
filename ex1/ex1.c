// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 5;
    int parent = getpid();
    fork();

    if (parent != getpid()){
        x = 100;
    }
    printf("pid: %d x: %d\n", (int) getpid(), x);

    return 0;
}
