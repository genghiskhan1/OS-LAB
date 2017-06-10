//Implement process scheduling using Priority
#include<iostream>
#include<cstdlib>
#include<climits>
#include<vector>
using namespace std;
struct process
{
 int no;
 int arrival;
 int burst;
 int priority;
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

int g_index=0,n;
vector<order> gantt;

static int cmp_arrive(const void *p1,const void *p2)
{
 process *a=(process*)p1;
 process *b=(process*)p2;
 if(a->arrival<b->arrival) return -1;
 else if(a->arrival==b->arrival) return 0;
 else return 1;
}

void printGantt()
{
 cout<<"\n\tGANTT CHART\n\n";
 for(int i=0;i<g_index;i++)
 {
  cout<<"\tP"<<gantt[i].pno+1;
 }
 cout<<endl;
 for(int i=0;i<g_index;i++)
 {
  cout<<"\t@"<<gantt[i].time;
 }
}

void display()
{
 float avgwait=0,avgturn=0;
 cout<<"\nPROCESS\tARRIVAL\tBURST\tPRIORITY\tFINISH\tWAITING\tTURNAROUND\n\n";
 for(int i=0;i<n;i++)
 {
  q[i].wait=q[i].finish-q[i].arrival-q[i].burst;
  q[i].turn=q[i].finish-q[i].arrival;
  cout<<"P"<<q[i].no<<"\t"<<q[i].arrival<<"\t"<<q[i].burst<<"\t"<<q[i].priority<<"\t"<<q[i].finish<<"\t"<<q[i].wait<<"\t"<<q[i].turn<<endl;
  avgwait+=q[i].wait;
  avgturn+=q[i].turn;
 }
 cout<<"\n\tAVERAGE WAITING TIME:\t"<<avgwait/n;
 cout<<"\n\tAVERAGE TURNAROUND TIME:\t"<<avgturn/n;
}

process *getMinPriority(int &curr)
{ 
 int min_priority=INT_MAX,index=-1;
 for(int i=0;i<n;i++)
 {
  if(q[i].priority<min_priority&&q[i].arrival<=curr&&q[i].remaining>0) 
  {
    min_priority=q[i].priority;
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
 cout<<"\n\tENTER ARRIVAL,BURST TIME AND PRIORITY\n";
 for(int i=0;i<n;i++)
 {
  q[i].no=i;
  cin>>q[i].arrival>>q[i].burst>>q[i].priority;
  q[i].remaining=q[i].burst; 
 }
 qsort(q,n,sizeof(process),cmp_arrive);
 int curr=q[0].arrival;
 process *p;
 while(isRemaining())
 {
  p=getMinPriority(curr);
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
 cout<<endl; 
 return 0;
}
