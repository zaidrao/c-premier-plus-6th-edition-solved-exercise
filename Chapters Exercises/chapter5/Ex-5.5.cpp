#include "iostream"

using namespace std;
 
int main()
{
	int total=0;
	string months[12]{"January","February", "March","April","May","June","July","August","September","October", "November","December"};
	int sales[12];
	for(int i=0;i<12;i++)
	{
	    cout<<"Enter "<<months[i]<<" book's Sales: ";
	    cin>>sales [i];
	    total=total+sales[i];
	}
	for(int i=0;i<12;i++)
	{
	    cout<<"In "<<months[i]<<" generated "<<sales[i]<<" Sale"<<endl;
	    
	}
	cout<<"Total sale in year is "<<total<<" of Books";
}