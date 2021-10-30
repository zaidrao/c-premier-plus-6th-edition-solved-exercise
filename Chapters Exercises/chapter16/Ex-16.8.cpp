#include <iostream>
#include <set>

using namespace std;

void show(const string & s)
{
	cout<<s<<" ";
}


int main()
{
	set<string> mat;
	set<string> pat;
	set<string> merge;
	cout<<"Enter Mat friends name: ";
	string temp;
	getline(cin,temp);
	while(temp != "quit")
	{
		mat.insert(temp);
		cout<<"Enter again (quit for end): ";
		getline(cin,temp);
	}
	cout<<"\nEnter Pat friends name: ";
	getline(cin,temp);
	while(temp != "quit")
	{
		pat.insert(temp);
		cout<<"Enter again (quit for end): ";
		getline(cin,temp);
	}
	// copy mat list
	copy(mat.begin(),mat.end(),insert_iterator<set<string>>(merge,merge.begin()));
	// copy pat list
	copy(pat.begin(),pat.end(),insert_iterator<set<string>>(merge,merge.end()));
	// show lists
	cout<<"Mat Friends: ";
	for_each(mat.begin(),mat.end(),show);
	cout<<"\nPat Friends: ";
	for_each(pat.begin(),pat.end(),show);
	cout<<"\nMerge list: ";
	for_each(merge.begin(),merge.end(),show);
}