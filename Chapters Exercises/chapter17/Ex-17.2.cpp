/*
Write a program that copies your keyboard input (up to the simulated end-of-file) to a file named on the command line.
*/


#include <iostream>
#include <fstream>


int main(int argc, char** argv)
{
	using namespace std;
	ofstream out;
	out.open(argv[1]);
	if(!out.is_open())
	{
		cout<<"Couldn't open file.";
		exit(EXIT_FAILURE);
	}
	cout<<"Enter input: ";
	char ch;
	// use eof command for terminate loop
	while (cin.get(ch))
	{
		out<<ch;
	}
	out.close();
}