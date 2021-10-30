#include "iostream"

using namespace std;

void show(int [],int,int);
int input(int [],int);
int calc(int[],int);
int main()
{
    int max=10;
    int scr[max];
    int siz=input(scr,max);
    if(siz!=0)
    {
    int av=calc(scr,siz);
    show(scr,siz,av);
    }
    else
    cout<<"No data.";
}
int input(int ar[],int n)
{
  cout<<"Enter 10 golf score (q to quit): ";
  int i;
  for( i=0;i<n;i++) 
  {
      int temp;
      cin>>temp;
      if(!cin)
      {
          cin.clear();
          cin.get();
          break;
      }
      ar[i]=temp;
  }
  return i;
}
int calc(int ar[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=ar[i];
    return sum/n; 
}
void show(int ar[],int n, int av)
{
   cout<<"All scores:";
   for(int i=0;i<n;i++)
   cout<<ar[i]<<", ";
   cout<<endl<<"Average of score: "<<av;
   
}