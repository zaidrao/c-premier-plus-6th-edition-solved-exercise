#include "iostream"

using namespace std;

double add(double,double);
double multi(double,double);
double sub(double,double);
typedef  double (*fun) (double,double);
double calculate (double,double,fun);
int main()
{
	fun arth[3]={add,multi,sub}; // fun is typedef without it (double (*arth[3]) (double,double) used
    char sym[3]={'+','*','-'};
	double x,y;
	cout<<"Enter 2 num for +, -, *: ";
	cin>>x>>y;
	for(int i=0;i<3;i++)
	{
	    
	    cout<<sym[i]<<" of numbers is: "<<calculate(x,y,arth[i])<<endl;
	}
}
double add(double x,double y)
{
    return x+y;
}
double multi(double x,double y)
{
    return x*y;
}
double sub(double x,double y)
{
    return x-y;
}
double calculate (double x,double y,fun tool)
{
    return (*tool)(x,y);
}