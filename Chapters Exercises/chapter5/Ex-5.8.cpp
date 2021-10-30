#include "iostream"
#include "cstring"

using namespace std;
 
int main()
{
	char word[20];
	int count=0;
	cin>>word;
	while (strcmp(word, "done"))
	{
	    count++;
	    cin>>word;
	}
	cout<<"You entered a total of "<<count<<" words.";
}