#include "iostream"
#include <cstring>

using namespace std;
class Person 
{ 
    private:
    static const int LIMIT = 25;
    string lname;
    char fname[LIMIT];
    public:
    Person() {lname = ""; fname[0] = '\0';  } // #1
    Person(const string & ln, const char * fn = "Heyyou");   // #2 // the following methods display lname and fname 
    void Show() const;        // firstname lastname format 
    void FormalShow() const;  // lastname, firstname format 
    };

 
int main()
{
	Person one;                       // use default constructor 
	Person two("Smythecraft");        // use #2 with one default argument 
	Person three("Dimwiddy", "Sam");  // use #2, no defaults 
	one.Show(); 
	cout << endl; 
	one.FormalShow();
	cout<<endl;
	two.Show(); 
	cout << endl; 
	two.FormalShow();
	cout<<endl;
	three.Show(); 
	cout << endl; 
	three.FormalShow();
	cout<<endl;
}
Person::Person(const string & ln, const char * fn)
{
    lname=ln;
    strcpy(fname, fn);
}

void Person::Show() const
{
    cout<<"lname and fname:"<<endl;
    cout<<fname<<" "<<lname;
}
void Person::FormalShow() const
{
    cout<<"Formal name:"<<endl;
    cout<<lname<<" "<<fname;
}