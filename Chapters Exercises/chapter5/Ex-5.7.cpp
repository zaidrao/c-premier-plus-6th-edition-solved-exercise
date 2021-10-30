#include "iostream"

using namespace std;

struct car{
    string company;
    int year;
};
 
int main()
{
    int in;
	cout<<"How many cars do you wish to catalog? ";
	cin>>in;
	car *pc=new car[in];
	for(int i=0;i<in;i++)
	{
	    cin.get();
	    ++i;
	    cout<<"Car #"<<i<<":"<<endl;
	    --i;
	    cout<<"Please enter the make: ";
	    getline(cin,pc[i].company);
	    cout<<"Please enter the year made: ";
	    cin>>pc[i].year;
	}
	cout<<"Here is your collection:"<<endl;
	for(int i=0;i<in;i++)
	{
	    cout<<pc[i].year<<" "<<pc[i].company<<endl;
	}
}