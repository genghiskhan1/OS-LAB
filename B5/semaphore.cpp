//Implement process synchronization using semaphores. (Producer And Consumer Problem)

#include<iostream>
#include<cstdlib>
using namespace std;
void producer();
void consumer();
int signal(int); 
int wait(int);
int x=0,mutex=1,empty=3,full=0;
int main()
{
 int n;
 while(1)
 {
  cout<<"\n\t1.PRODUCER\n\t2.CONSUMER\n\t3.EXIT\n\tENTER CHOICE:\t";
  cin>>n;
  switch(n)
  {
   case 1: if(mutex==1&&empty!=0)
             producer();
           else
	     cout<<"\n\tBUFFER IS FULL";
           break;

   case 2: if(mutex==1&&full!=0)
             consumer();
	   else
	     cout<<"\n\tBUFFER IS EMPTY";
           break;
   
   case 3: exit(0);
           break;
   
   default: break;
  }
 }
}

int signal(int s)
{
 return (++s);
}

int wait(int s)
{
 return (--s);
}

void producer()
{
 mutex=wait(mutex);
 full=signal(full);
 empty=wait(empty);
 x++;
 cout<<"\n\tPRODUCER PRODUCES ITEM:\t"<<x;
 mutex=signal(mutex);
}

void consumer()
{
 mutex=wait(mutex);
 full=wait(full);
 empty=signal(empty);
 cout<<"\n\tCONSUMER CONSUMES ITEM:\t"<<x;
 x--;
 mutex=signal(mutex);
}
