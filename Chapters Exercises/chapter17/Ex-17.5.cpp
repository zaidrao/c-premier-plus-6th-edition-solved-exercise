#include <iostream>
#include <set>
#include <fstream>

std::ofstream outFile("matnpat.dat");
void show(const std::string & s)
{
	std::cout<<s<<std::endl;
}
void output(const std::string & s)
{
	outFile<<s<<std::endl;
}
int main()
{
	using namespace std;
	// Mat file 
	ifstream file1("mat.dat");
	if(!file1.is_open())
	{
		cerr<<"Couldn't open input file 1";
		exit(EXIT_FAILURE);
	}
	// Pat file 2
	ifstream file2("pat.dat");
	if(!file2.is_open())
	{
		cerr<<"Couldn't open input file 2";
		exit(EXIT_FAILURE);
	}
	// merege output file
	if(!outFile.is_open())
	{
		cerr<<"Couldn't open output file";
		exit(EXIT_FAILURE);
	}
	
	set<string> mat;
	set<string> pat;
	set<string> merge;
	string temp;
	while(getline(file1,temp))
	{
		mat.insert(temp);
	}
	while(getline(file2,temp))
	{
		pat.insert(temp);
	}
	
	// copy mat list
	copy(mat.begin(),mat.end(),insert_iterator<set<string>>(merge,merge.begin()));
	// copy pat list
	copy(pat.begin(),pat.end(),insert_iterator<set<string>>(merge,merge.end()));
	
	// copy merege list in output file
	
	for_each(merge.begin(),merge.end(),output);
	
	// show lists
	cout<<"Mat Friends:"<<endl;
	for_each(mat.begin(),mat.end(),show);
	cout<<"\nPat Friends:"<<endl;
	for_each(pat.begin(),pat.end(),show);
	cout<<"\nMerge list:"<<endl;
	for_each(merge.begin(),merge.end(),show);
}