#include "iostream"

using namespace std;
 
int harmonic (int,int);
int main()
{
	cout<<"Enter two number (0 to quit): ";
	int x,y;
	while(true)
	{
	    while(!(cin>>x>>y))
	   {cin.clear();
	   cin.get();
	   cout<<"Bad input, Enter again: ";
	   }
	    int r;
	    if(x==0||y==0)
	    break;
	    r=harmonic(x,y);
	    cout<<"Harmonic:"<<r<<endl;
	    cout<<"Enter: ";
	}
}

int harmonic (int x,int y)
{
    return 2*x*y/(x+y);
}