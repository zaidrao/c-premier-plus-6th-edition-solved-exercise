#include "iostream"

using namespace std;
 
int main()
{
	int total[4];
	string months[12]{"January  ","February ", "March    ","April    ","May      ","June     ","July     ","August   ","September","October  ", "November ","December "};
	int sales[12][3]=
	{
	    {45,3,5},
	    {45,3,5},
	    {45,3,5},
	    {45,3,5},
	    {45,3,5},
	    {45,3,5},
	    {45,3,5},
	    {45,3,5},
	    {45,3,5},
	    {45,3,5},
	    {45,3,5},
	    {45,3,5}    
	};
	cout<<"Years:\t\t2018\t2019\t2020"<<endl;
	for(int i=0;i<12;i++)
	{
	    cout<<months[i]<<":\t";
	for(int j=0;j<3;j++)
	{
	    total [j]+=sales[i][j];
	    cout<<sales[i][j]<<"\t "; 
	}
	cout<<endl;
	}
	cout<<endl;
	for(int j=1;j<4;j++)
	cout<<"Total sale in "<<j<<"  year is "<<total[j-1]<<" of Books"<<endl;
	cout<<"Total 3 years sale is: "<<total[0]+total[1]+total[2];
}