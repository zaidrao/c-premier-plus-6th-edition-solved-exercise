#include "iostream"

using namespace std;

int fact(int);
 
int main()
{
	int num;
	cout<<"Enter num (q for quite): ";
	while (cin>>num)
	{
	    cout<<"Factorial of "<<num<<" is "<<fact(num)<<endl;
	    cout<<"Enter num (q for quite): ";
	}
}
int fact(int n)
{
    if (n==0)
    return 1;
    return n*fact(n-1);
}