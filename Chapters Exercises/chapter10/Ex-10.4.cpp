#include "iostream"

namespace SALES
{
    const int QUARTERS = 4;
    class Sales
    {
        private:
        double sales[QUARTERS];
        double average;
        double max;
        double min;
        public:
        Sales(){}; // default
        Sales(const double ar[], int n);
        void setSales();
        void showSales() const;
    };
}     
 
int main()
{
	using namespace SALES;
	Sales s2;
	double sale[3]{43,65,33};
	Sales s1(sale,3);
	s1.showSales();
	s2.setSales();
	s2.showSales();
	
}
SALES::Sales::Sales(const double ar[], int n)
    {
        double sum=0;
        double tempg=0,temps=-1;
        for(int i=0;i<QUARTERS;i++)
        {
            if(i<n)
            {
            sales[i]=ar[i];
            sum+=ar[i];
            }
            else
            sales[i]=0;
            if(sales[i]>tempg)
            {
                tempg=sales[i];
            }
          if(temps==-1||sales[i]<temps)
           {
                temps=sales[i];
            }
        }
        average=sum/n;
        max=tempg;
        min=temps;
    }
void SALES::Sales::setSales()
{
       double sal[QUARTERS];
       std::cout<<"Enter Quarter sales:\n";
       for(int i=0;i<QUARTERS;i++)
       {
          std::cin>>sal[i];
       }
      *this= Sales(sal,QUARTERS);
 }
void SALES::Sales::showSales() const
{
    using std::cout;
        using std::endl;
        for(int i=0;i<QUARTERS;i++)
        cout<<"#"<<i+1<<" : "<<sales[i]<<endl;
        cout<<"Maximum sale: "<<max<<endl;
        cout<<"Minimum sale: "<<min<<endl;
        cout<<"Average sale: "<<average<<endl;
}