#include "iostream"
#include <cstring>

const int LEN=19;
class plorg{
    private:
    char name[LEN];
    int ci;
    public:
    plorg(const char * n="plorga",int c=50);
    void cc(int c);
    void show() const;
};

using namespace std;
 
int main()
{
	plorg p1;
	p1.show();
	plorg p2("Fhlogy gd",435);
	p2.show();
	p1.cc(324);
	p1.show();
	
}
plorg::plorg(const char * n,int c)
{
    strcpy(name,n);
    ci=c;
}
void plorg::cc(int c)
{
    ci=c;
}
void plorg::show() const
{
    cout<<name<<" : "<<ci<<endl;
}