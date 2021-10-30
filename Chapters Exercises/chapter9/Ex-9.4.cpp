//Header file (prototype+definations)
#include "iostream"

namespace SALES
{
    const int QUARTERS = 4;
    struct Sales
    {
        double sales[QUARTERS]{0};
        double average;
        double max;
        double min;
    };
    void setSales(Sales & s, const double ar[], int n)
    {
        double sum=0;
        double tempg=0,temps=-1;
        for(int i=0;i<QUARTERS;i++)
        {
            if(i<n)
            {
            s.sales[i]=ar[i];
            sum+=ar[i];
            }
            else
            s.sales[i]=0;
            if(s.sales[i]>tempg)
            {
                tempg=s.sales[i];
            }
          if(temps==-1||s.sales[i]<temps)
           {
                temps=s.sales[i];
            }
        }
        s.average=sum/n;
        s.max=tempg;
        s.min=temps;
    }
    void setSales(Sales & s)
    {
       double sal[QUARTERS];
       std::cout<<"Enter Quarter sales:\n";
       for(int i=0;i<QUARTERS;i++)
       {
          std::cin>>sal[i];
       }
       setSales(s,sal,QUARTERS);
    }
    void showSales(const Sales & s)
    {
        using std::cout;
        using std::endl;
        for(int i=0;i<QUARTERS;i++)
        cout<<"#"<<i+1<<" : "<<s.sales[i]<<endl;
        cout<<"Maximum sale: "<<s.max<<endl;
        cout<<"Minimum sale: "<<s.min<<endl;
        cout<<"Average sale: "<<s.average<<endl;
        
    }
    
}

//main.cpp file
 
int main()
{
	using namespace SALES;
	Sales s1,s2;
	double sale[]{455,657,3366,5666};
	setSales(s1,sale,2);
	showSales(s1);
	setSales(s2);
	showSales(s2);
}