//Write a C program to do the followung : 
//Using fork create a child process.The child prints its own process id and id of
//its parents and then exits. The parent process waits for its child to finish
//(by executing the wait() and prints its own process id and the id of its 
//child process and then exits

#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
 pid_t pid;
 pid=fork();
 if(pid<0)
 {
  printf("\n\tERROR OCCURED"); 
  exit(-1);
 }
 else if(pid==0)
 {
  printf("\n\tCHILD PROCESS ID:%d\tPARENT PROCESS ID:%d",getpid(),getppid());
 }
 else
 {
  wait(NULL);
  printf("\n\tPARENT PROCESS ID:%d\tCHILD PROCESS ID:%d",getpid(),pid);
  exit(0);
 }
 return 0;
}
