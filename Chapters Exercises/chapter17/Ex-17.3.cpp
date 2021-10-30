#include <iostream>
#include <fstream>


// filename in command line arguments

int main(int argc, char** argv)
{
	using namespace std;
	ofstream out;
	ifstream in;
	// open first file for read input
	in.open(argv[1]);
	if(!in.is_open())
	{
		cout<<"Couldn't open input file.";
		exit(EXIT_FAILURE);
	}
	out.open(argv[2]);
	if(!out.is_open())
	{
		cout<<"Couldn't open output file.";
		exit(EXIT_FAILURE);
	}
	char ch;
	while(in.get(ch))
	{
		out<<ch;
	}
	cout<<"Finished";
}