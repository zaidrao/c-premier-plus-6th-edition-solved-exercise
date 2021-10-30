#include "iostream"
#include <cstring>
using namespace std; 

struct stringy {
    char * str;
    int ct;
    };
void set(stringy &, char []);
void show(const stringy &,int n=0);
void show(const char [],int n=0);
int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
	return 0;
}
void set(stringy & bean, char ch[])
{
    int l=strlen(ch);
    bean.ct=l;
    char * ps=new char [l+1];
    strcpy(ps,ch);
    bean.str=ps;
}
void show(const stringy & bean,int n)
{
    if(n>0)
    {
        for(int i=1;i<=n;i++)
        cout<<bean.str<<endl;
    }
    else
    cout<<bean.str<<endl;
}
void show(const char ch[],int n)
{
    if(n>0)
    {
        for(int i=1;i<=n;i++)
        cout<<ch<<endl;
    }
    else
    cout<<ch<<endl;
}