//Implement process scheduling using Round Robin
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
 int finish;
 int wait;
 int turn;
 int remaining;
}*q;

struct order
{
 int pno;
 int time;
};

int g_index=0,n;
int quantum;
vector<order>gantt;

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
  cout<<" P"<<gantt[i].pno+1;
 }
 cout<<endl;
 for(int i=0;i<g_index;i++)
 {
  cout<<" @"<<gantt[i].time;
 }
}

void display()
{ 
 float avgwait=0,avgturn=0;
 cout<<"\nPROCESS\tARRIVAL\tBURST\tFINISH\tWAITING\tTURNAROUND\n";
 for(int i=0;i<n;i++)
 {
  q[i].wait=q[i].finish-q[i].arrival-q[i].burst;
  q[i].turn=q[i].finish-q[i].arrival;
  cout<<q[i].no+1<<"\t"<<q[i].arrival<<"\t"<<q[i].burst<<"\t"<<q[i].finish<<"\t"<<q[i].wait<<"\t"<<q[i].turn<<endl;
  avgwait+=q[i].wait;
  avgturn+=q[i].turn;
 }
 cout<<"\n\tAVERAGE WAITING TIME:\t"<<avgwait/n;
 cout<<"\n\tAVERAGE TURNAROUND TIME:\t"<<avgturn/n;
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
 cout<<"\n\tENTER THE NUMBER OF PROCESSES:\t";
 cin>>n;
 q=new process[n];
 cout<<"\n\tENTER ARRIVAL AND BURST TIME\n";
 for(int i=0;i<n;i++)
 {
  q[i].no=i;
  cin>>q[i].arrival>>q[i].burst;
  q[i].remaining=q[i].burst;
 }
 cout<<"\n\tENTER QUANTUM:\t";
 cin>>quantum;
 qsort(q,n,sizeof(process),cmp_arrive);
 int curr=q[0].arrival; 
 int count=0;
 for(int i=0;isRemaining();i=(i+1)%n)
 {
   if(q[i].arrival<=curr&&q[i].remaining>0)
   {
    count=0;
    order g;
    g.pno=q[i].no;
    g.time=curr;
    gantt.push_back(g);
    g_index++;
    curr+=(q[i].remaining>=quantum)?quantum:q[i].remaining;
    q[i].remaining=(q[i].remaining>=quantum)?q[i].remaining-quantum:0;
    if(q[i].remaining==0)
    {
     q[i].finish=curr;
    }
   }
   else
   {
    count++;
   }
   if(count==n)
   {
    for(int j=0;j<n;j++)
    {
     if(q[j].arrival>curr)
     {
      curr=q[j].arrival;
      break;
     }
    }
    count=0;
   }
  }
 printGantt();
 display(); 
 cout<<endl;
 return 0;
}
