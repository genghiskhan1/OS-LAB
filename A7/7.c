//Write a C program using process system call (fork,exit)

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
 int i; 
 pid_t pid;
 for(i=0;i<3;i++)
 {
  pid=fork();
  if(pid<0)
  {
   printf("\n\tERROR OCCURED");
   exit(-1);
  } 
  else if(pid==0)
  {
   printf("\n\tCHILD PROCESS (%d) : %d CREATED\n",i+1,getpid());
  }
  else 
  {
   wait(NULL);
   if(i==2)
   {
    printf("\n-------------------");
   }
   printf("\n\tCHILD PROCESS (%d) COMPLETED",i+1);
   exit(0);  
  }
 }
 return 0;
}
