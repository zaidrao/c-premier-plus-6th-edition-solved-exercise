#include "iostream"
#include "string"
#include "cctype"

using namespace std;

void upp(const string &);
int main()
{
	string str;
	cout<<"Enter string (q to quit): ";
	getline(cin,str);
	while (!(str=="q"))
	{
 	upp(str);
 	cout<<"\nEnter again: ";
 	getline(cin,str);
	}
}
void upp(const string & st)
{
    int n;
    n=st.size();
    for(int i=0;i<n;i++)
    {
        cout<<char(toupper(st[i]));
    }
}