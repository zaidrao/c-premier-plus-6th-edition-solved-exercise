#include "iostream"
#include "array"

using namespace std;
 
int main()
{
	const int max=10;
	array<double, max> du;
	int i=0;
	cout<<"Enter number: ";
	while (cin>>du[i]&&i<max)
	    i++;
	double sum=0;
	for(int j=0;j<i;j++)
	sum+=du[j];
	double av=sum/i;
	int count=0;
	cout<<"The Average of "<<i<<" numbers is: "<<av;
	for(int j=0;j<i;j++)
	{
	    if(av>du[j])
	    count++;
	}
	cout<<endl<<count<<" number greater than Average.";
}