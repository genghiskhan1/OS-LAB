//Implement process scheduling using FCFS
#include<iostream>
#include<cstdlib>
using namespace std;
struct process
{
 int no;
 int arrival;
 int burst;
 int wait;
 int finish;
 int turnaround;
};

static int cmp_process(const void *p1,const void *p2)
{
 process *a=(process*) p1;
 process *b=(process*) p2;
 if(a->arrival < b->arrival) 
   return -1;
 else if(a->arrival==b->arrival) 
  return 0;
 else return 1;
}

void display(process *q,int n)
{
 float avgwait=0,avgturn=0,current=0;
 cout<<"\n\tGANTT CHART\n\n";
 
 for(int i=0;i<n;i++)
 {
  cout<<"\tP"<<q[i].no;
 }
 cout<<"\n";
 for(int i=0;i<n;i++)
 {
  cout<<"\t@ "<<current;
  current+=q[i].burst;
  q[i].finish=current;
 }

 cout<<"\nPROCESS\tARRIVAL\tBURST\tFINISH\tWAIT\tTURNAROUND";
 for(int i=0;i<n;i++)
 {
  cout<<"\nP"<<q[i].no<<"\t"<<q[i].arrival<<"\t"<<q[i].burst<<"\t"<<q[i].finish<<"\t"<<q[i].wait<<"\t"<<q[i].turnaround;
  avgwait+=q[i].wait;
  avgturn+=q[i].turnaround;
 }
 cout<<"\n\tAVERAGE WAITING TIME:\t"<<avgwait/n;
 cout<<"\n\tAVERAGE TURNAROUND TIME:\t"<<avgturn/n;
}

int main()
{
 int n;
 cout<<"\n\tENTER NUMBER OF PROCESSES:\t";
 cin>>n;
 process q[n];
 cout<<"\n\tENTER ARRIVAL AND BURST TIME FOR EACH PROCESS\n"; 
 for(int i=0;i<n;i++)
 {
  q[i].no=i+1;
  cin>>q[i].arrival>>q[i].burst;
 }
 qsort(q,n,sizeof(process),cmp_process);
 int current=0;
 for(int i=0;i<n;i++)
 {
  current=(q[i].arrival>current?q[i].arrival:current);
  q[i].wait=current-q[i].arrival;
  current+=q[i].burst;
  q[i].turnaround=q[i].wait+q[i].burst;
 }
 cout<<"\n\tFCFS ORDER\n\n";
 display(q,n);
 return 0;
}
