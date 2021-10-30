#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{
	using namespace std;
	// input file 1
	ifstream file1("any.txt");
	if(!file1.is_open())
	{
		cerr<<"Couldn't open input file 1";
		exit(EXIT_FAILURE);
	}
	// input file 2
	ifstream file2("abc.txt");
	if(!file2.is_open())
	{
		cerr<<"Couldn't open input file 2";
		exit(EXIT_FAILURE);
	}
	// open output file
	ofstream outFile("output.txt");
	if(!outFile.is_open())
	{
		cerr<<"Couldn't open output file";
		exit(EXIT_FAILURE);
	}
    char ch1[100];
    char ch2[100];
    
    // read both file line by line and write in output file
    while (file1.getline(ch1,100) &&
    	   file2.getline(ch2,100))
    {
   	 outFile<<ch1<<" "<<ch2<<endl;
    }
    
    // write last read line in output
    outFile<<ch1<<" "<<ch2<<endl;
    
    // check if either file reach end or not
	// if not then again read and write
    if(!file1.eof())
    {
    	while (file1.getline(ch1,100))
    	outFile<<ch1<<endl;
    }
    else if(!file2.eof())
    {
    	while (file2.getline(ch2,100))
    	outFile<<ch2<<endl;
    }
    else
		cerr<<"Both file reach end\n";
	cerr<<"Finished";
}