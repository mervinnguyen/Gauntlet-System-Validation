#Creating a framework for drivers of robotic arm project

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int pidFunction(){
    int pid = fork();
    if(pid == 0){
        return 1;
    }
    else if(pid > 0){
        return 0;
    }
    else{
        return -1;
    }
}
int main(){
    int pid = pidFunction();
    if(pid == 1){
        printf("Child process created\n");
        execlp("python3", "python3", "ff.py", NULL);
    }
    else if(pid == 0){
        printf("Parent process\n");
        wait(NULL);
    }
    else{
        printf("Error\n");
    }
    return 0;
}