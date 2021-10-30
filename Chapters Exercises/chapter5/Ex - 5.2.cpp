#include "iostream"
#include "array"

using namespace std;
 
int main()
{
	array<long double, 100> fact;
	fact[0]=fact[1]=1;
	for(int i=2;i<=100;i++)
	fact[i]=i*fact[i-1];
	for(int i=0;i<=100;i++)
	cout<<i<<"! = "<<fact[i]<<endl;
}