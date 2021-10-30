#include "iostream"
#include "cstring"

class Cow
{
    char name[20];
    char * hobby;
    double weight;
    public:
    Cow();
    Cow(const char * nm, const char * ho, double wt);
    Cow(const Cow &c);
    ~Cow();
    Cow & operator=(const Cow & c);
    void ShowCow() const;  // display all cow data
};
using std::cout;
using std::endl;
int main()
{
	Cow c1;
	Cow c2("Kshsh","Jsjs",55);
	Cow c3=c2;
	c1=c3;
	c1.ShowCow();
	c2.ShowCow();
	c3.ShowCow();
	
}
Cow::Cow()
{
    name[0]='\0';
    hobby=NULL;
    weight=0;
    cout<<"Default constructor "<<name<<endl;
}
Cow::Cow(const char * nm, const char * ho, double wt)
{
    strcpy(name,nm);
    hobby=new char[strlen(ho)+1];
    strcpy(hobby,ho);
    weight=wt;
    cout<<"Modify constructor "<<name<<endl;
}
Cow::Cow(const Cow &c)
{
    strcpy(name,c.name);
    hobby=new char[strlen(c.hobby)+1];
    strcpy(hobby,c.hobby);
    weight=c.weight;
    cout<<"Copy constructor "<<name<<endl;
}
Cow::~Cow()
{
    cout<<"Distuctor"<<name<<endl;
    delete []hobby;
}
Cow & Cow::operator=(const Cow & c)
{
    if (this == &c)            // object assigned to itself
    return *this;          // all done
    delete [] hobby;     
    strcpy(name,c.name);
    hobby=new char[strlen(c.hobby)+1];
    strcpy(hobby,c.hobby);
    weight=c.weight;
    return *this; 
}
void Cow::ShowCow() const
{
    cout<<"Name: "<<name<<"\nHobby: "<<hobby<<"\nWeight: "<<weight<<endl;
}