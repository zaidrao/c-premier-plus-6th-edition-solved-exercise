#include "iostream"
#include "cctype"

using namespace std;
 
int main()
{
	char ch;
	while((ch=cin.get())!='@')
	{
	    cout<<endl;
	    if(isalpha(ch))
	     {  if(isupper(ch))
	       cout<<char(tolower(ch));
	       else
           cout<<char(toupper(ch));}
         else
            cout<<char(ch);
	}
}