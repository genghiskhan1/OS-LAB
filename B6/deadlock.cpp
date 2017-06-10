//Implement process handling using deadlock
#include<iostream>
#include<cstdlib>
using namespace std;
struct process
{
 int max[3];
 int need[3];
 int allocated[3];
 string name;
 bool isProcessed;
};

int main()
{
 int total[3],available[3],n,i=0;
 string sequence="";
 bool flag;
 cout<<"\n\tENTER THE TOTAL NUMBER OF PROCESSES:\t";
 cin>>n;
 process *p=new process[n];
 cout<<"\n\tENTER THE TOTAL NUMBER OF AVAILABLE RESOURCES:\t";
 cin>>total[0]>>total[1]>>total[2];
 for(int i=0;i<n;i++)
 {
  cout<<"\n\tENTER THE PROCESS NAME:\t";
  cin>>p[i].name;
  cout<<"\n\tENTER THE MAXIMUM NUMBER OF RESOURCES OF THE PROCESS\n";
  cin>>p[i].max[0]>>p[i].max[1]>>p[i].max[2];
  cout<<"\n\tENTER THE NUMBER OF ALLOCATED RESOURCES FOR THE PROCESS\n";
  cin>>p[i].allocated[0]>>p[i].allocated[1]>>p[i].allocated[2];
  p[i].need[0]=p[i].max[0]-p[i].allocated[0];
  p[i].need[1]=p[i].max[1]-p[i].allocated[1];
  p[i].need[2]=p[i].max[2]-p[i].allocated[2];
  p[i].isProcessed=false;
 }
 available[0]=total[0];
 available[1]=total[1];
 available[2]=total[2];
 for(int i=0;i<n;i++)
 {
  available[0]-=p[i].allocated[0];
  available[1]-=p[i].allocated[1];
  available[2]-=p[i].allocated[2];
 }
 while(i<n)
 {
  int select=-1;
  for(int j=0;j<n;j++)
  {
   if(p[j].need[0]<=available[0]&&p[j].need[1]<=available[1]&&p[j].need[2]<=available[2]&&!p[j].isProcessed)
   {  
    select=j;
    flag=true;
    break;
   }
  }
  if(flag)
  {
   flag=false;
   p[select].isProcessed=true;
   sequence.append(p[select].name);
   sequence.append(",");
   available[0]+=p[select].allocated[0];
   available[1]+=p[select].allocated[1];
   available[2]+=p[select].allocated[2];
   i++;
  }
  else 
  {
   cout<<"\n\tNO SAFE SEQUENCE EXISTS";
   exit(0);
  }
 }
 cout<<"\n\tSAFE SEQUENCE IS:\t"<<sequence;
 return 0;
}
   

