#include "iostream"

using namespace std;
 
int main()
{
	float DaIn=100; //Daphne investment
	float LeIn=100; // Leo Investment
	float DaI=0,LeI=0; //interest
	for(int i=0;i<5;i++) // 5 year interest of Daphne
	DaI+=0.10*DaIn;
	DaIn=DaIn+DaI;
	int count=0;
	do{
	    LeI=0.05*LeIn;
	    LeIn=LeI+LeIn;
	    count++;
	    
	}while(LeIn<=DaIn);// check how many year take to leo to exceed daphne with interest of 5
	
	cout<<"Total investment of Daphne in 5 year: "<<DaIn<<endl;
	cout<<"Total investment of Leo in "<<count<<" year: "<<LeIn<<endl;
	
	
}