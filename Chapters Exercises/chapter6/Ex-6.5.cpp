#include "iostream"

using namespace std;
 
int main()
{
	double income;
	double sum=0;
	cout<<"Enter income for calculate tax: ";
    while(cin>>income && income>0)
    {
        if(income<=5000)
        sum+=0.0*income;
        else if(income<=15000)
       {double temp;
        temp=income-5000;
        sum+=0.0*5000;
        sum+=(0.10*temp);
       }
       else if(income<=35000)
       {double temp;
        temp=income-15000;
        sum+=((0.0*5000)+(0.10*10000));
        sum+=(0.15*temp);
       }
       else if(income>35000)
       {double temp;
        temp=income-35000;
        sum+=((0.0*5000)+(0.10*10000)+(0.15*20000));
        sum+=(0.20*temp);
       }
       cout<<"Total tax is "<<sum<<endl;
       cout<<"Enter again: ";
        
    }
}