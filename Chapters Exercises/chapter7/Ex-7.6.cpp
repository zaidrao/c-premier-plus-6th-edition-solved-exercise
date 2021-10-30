#include "iostream"

using namespace std;

void show(int [],int);
int input(int [],int);
void reverse(int[],int);
int main()
{
    int max=5;
    int scr[max];
    int siz=input(scr,max);
    if(siz!=0)
    {
    cout<<"Before reverse: ";
    show(scr,siz);
    reverse(scr,siz);
    cout<<"\nAfter reverse: ";
    show(scr,siz);
    }
    else
    cout<<"No data.";
}
int input(int ar[],int n)
{
  cout<<"Enter 5 values (q to quit): ";
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
void reverse(int ar[],int n)
{
    int temp;
    for(int i=0;i<n/2;i++)
    {
        temp=ar[i];
        ar[i]=ar[(n-1)-i];
        ar[(n-1)-i]=temp;
    }
}
void show(int ar[],int n)
{
   cout<<"All values:";
   for(int i=0;i<n;i++)
   cout<<ar[i]<<", ";
   
}