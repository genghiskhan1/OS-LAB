//Implement the FIFO page replacement algorithm

#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
 int n,t,pageFaults=0,nextToReplace=0; 
 cout<<"\n\tENTER NUMBER OF FRAMES:\t";
 cin>>n; 
 cout<<"\n\tENTER NUMBER OF MEMORY ELEMENTS:\t";
 cin>>t;
 int frames[n];
 for(int i=0;i<n;i++)
 {
  frames[i]=-1;
 }
 for(int i=0;i<t;i++)
 {
  int temp;
  cin>>temp;
  bool flag=false;
  cout<<temp;
  for(int j=0;j<n;j++)
  {
   if(frames[j]==temp)
   {
     flag=true;
     cout<<endl;
   }
  }
  if(flag)continue;
  frames[nextToReplace]=temp;
  pageFaults++;
  nextToReplace=(nextToReplace+1)%n;
  cout<<":";
  for(int j=0;j<n;j++)
  {
   cout<<frames[j]<<" ";
  }
  cout<<endl;
 }
 cout<<"\n\tNUMBER OF PAGE FAULTS:\t"<<pageFaults;
 return 0;
}
