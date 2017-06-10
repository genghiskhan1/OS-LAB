//Implement process scheduling using SJF
#include<iostream>
#include<climits>
#include<cstdlib>
#include<vector>
using namespace std;

struct process
{
 int no;
 int arrival;
 int burst;
 int wait;
 int turn;
 int remaining;
 int finish;
}*q;

struct order
{
 int pno;
 int time;
};

int g_index=0;
int n;
vector<order>gantt;

static int cmp_arrive(const void *p1,const void *p2)
{
 process *a=(process*)p1;
 process *b=(process*)p1;
 if(a->arrival<b->arrival) return -1;
 else if(a->arrival==b->arrival) return 0;
 else return 1;
}

void printGantt()
{
 cout<<"\n\tGANTT CHART\n";
 for(int i=0;i<g_index;i++)
 {
  cout<<"\tP "<<gantt[i].pno+1;
 }
 cout<<endl;
 for(int i=0;i<g_index;i++)
 {
  cout<<"\t@"<<gantt[i].time;
 }
 cout<<"\n";
}

void display()
{
 float avgwait=0,avgturn=0;
 cout<<"\n\tPROCESS\tARRIVAL\tBURST\tFINISH\tWAITING\tTURNAROUND\n";
 for(int i=0;i<n;i++)
 {
  q[i].wait=q[i].finish-q[i].arrival-q[i].burst;
  q[i].turn=q[i].finish-q[i].arrival;
  cout<<"\n\tP"<<q[i].no+1<<"\t"<<q[i].arrival<<"\t"<<q[i].burst<<"\t"<<q[i].finish<<"\t"<<q[i].wait<<"\t"<<q[i].turn;
  avgwait+=q[i].wait;
  avgturn+=q[i].turn;
 }
 cout<<"\n\tAVERAGE WAITING TIME:\t"<<avgwait/n;
 cout<<"\n\tAVERAGE TURNAROUND TIME:\t"<<avgturn/n;
}

process *getShortestJob(int &curr)
{
 int min_time=INT_MAX,index=-1;
 for(int i=0;i<n;i++)
 {
  if(q[i].remaining<min_time&&q[i].arrival<=curr&&q[i].remaining>0)
  {
   min_time=q[i].remaining;
   index=i; 
  }
 }
 if(index==-1) return NULL;
 return &q[index];
}

bool isRemaining()
{
 for(int i=0;i<n;i++)
 {
  if(q[i].remaining>0)
  {
   return true;
  }
 }
 return false;
}

int main()
{
 cout<<"\n\tENTER NUMBER OF PROCESSES:\t";
 cin>>n;
 q=new process[n];
 cout<<"\n\tENTER ARRIVAL AND BURST TIMES OF EACH PROCESS\n";
 for(int i=0;i<n;i++)
 {
  q[i].no=i;
  cin>>q[i].arrival>>q[i].burst;
  q[i].remaining=q[i].burst;
 }
 qsort(q,n,sizeof(process),cmp_arrive);
 int curr=q[0].arrival;
 process *p;
 while(isRemaining())
 {
  p=getShortestJob(curr);
  if(p!=NULL)
  {
   p->remaining--;
   if(p->remaining==0)
   {
     p->finish=curr+1;
   }
   if(g_index==0||gantt[g_index-1].pno!=p->no)
   {
    order g;
    g.pno=p->no;
    g.time=curr;
    gantt.push_back(g);
    g_index++;
   }
  }
 curr++;
 }
 printGantt();
 display();
 return 0;
}
