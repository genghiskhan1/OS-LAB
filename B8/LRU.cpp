//Implement LRU page replacement algorithm

#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
 int n,t,i,j,max,pos,foundPos,nextToReplace=0,pageFaults=0;
 cout<<"\n\tENTER NUMBER OF FRAMES:\t";
 cin>>n;
 cout<<"\n\tENTER NUMBER OF MEMORY ELEMENTS:\t";
 cin>>t;
 int frames[n],last[n];
 for(i=0;i<n;i++)
 {
   frames[i]=-1;
   last[i]=999;
 }
 for(i=0;i<t;i++)
 {
  int temp;
  cin>>temp;
  bool flag=false;
  cout<<temp;
  for(j=0;j<n;j++)
  {
   last[j]++;
  }
  for(j=0;j<n;j++)
  {
   if(frames[j]==temp)
   {
    foundPos=j;
    flag=true;
    cout<<endl;
   }
  }
  if(flag) 
  {
   last[foundPos]=0;
   continue;
  }
  pageFaults++;
  max=0;
  for(j=0;j<n;j++)
  {
   if(last[j]>max)
   {
    max=last[j];
    pos=j; 
   }
  }
  nextToReplace=pos;
  frames[nextToReplace]=temp;
  last[nextToReplace]=0;
  cout<<":";
  for(j=0;j<n;j++)
  {  
   cout<<frames[j]<<" ";
  }
  cout<<endl;
 }
 cout<<"\n\tNUMBER OF PAGE FAULTS:\t"<<pageFaults;
 return 0;
}
