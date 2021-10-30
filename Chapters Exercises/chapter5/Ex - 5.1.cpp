#include "iostream"

using namespace std;
 
int main()
{
    int x,y;
    cin>>x>>y;
    for(int i=++x;i<=y;i++)
    x=x+i;
    cout<<endl<<x-1;
}