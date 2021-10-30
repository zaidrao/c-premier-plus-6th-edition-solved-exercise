#include "iostream"
#include "fstream"
#include "cstdlib" // for exit()

using namespace std;
 
int main()
{
	ifstream in;
	in.open("info.txt");
	if (!in.is_open())
	{
	    cout<<"File not open";
	    exit(EXIT_FAILURE);
	}
	int count=0;
	char ch;
	while (in>>ch)
	{
	    count++;
	}
	cout<<"Total Words: "<<count;
}