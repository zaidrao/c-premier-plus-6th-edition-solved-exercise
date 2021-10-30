#include "iostream"
#include "cstring"
class Cd
{
    // represents a CD disk
  private:
    char * performers;
    char * label;
    int selections;  // number of selections
    double playtime; // playing time in minutes
  public:
    Cd(const char *s1, const char *s2, int n, double x);
    Cd(const Cd & d);
    Cd & operator=(const Cd & d);
    Cd();
    virtual ~Cd();
    virtual void Report() const; // reports all CD data
};
class Classic : public Cd
{
  private:
    char* work;

  public:
    Classic(const char *s1, const char *s3, const char *s4, int n, double x);
    Classic(const Classic & c);
    Classic();
    ~Classic();
    Classic(const Cd &c, const char *s1);
    virtual void Report() const;
    Classic & operator=(Classic & c);
};
using namespace std;

void Bravo(const Cd &disk);

int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
   Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
    Cd *pcd = &c1;
    cout << "Using object directly:\n";
    c1.Report(); // use Cd method
    c2.Report(); // use Classic method
    cout << "Using type cd * pointer to objects:\n";
    pcd->Report(); // use Cd method for cd object
    pcd = &c2;
    pcd->Report(); // use Classic method for classic object
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();
}
Cd::Cd(const char *s1, const char *s2, int n, double x)
{
    performers=new char[strlen(s1)+1];
    strcpy(performers, s1);
    label=new char[strlen(s2)+1];
    strcpy(label, s2);
    selections = n;
    playtime = x;
}
Cd::Cd()
{
    performers= NULL;
    label = NULL;
    selections = 0;
    playtime = 0;
}
Cd::Cd(const Cd & d)
{
    performers=new char[strlen(d.performers)+1];
    strcpy(performers, d.performers);
    label=new char[strlen(d.label)+1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}
Cd & Cd::operator=(const Cd & d)
{
    if(this==&d)
    return *this;
    delete [] performers;
    delete [] label;
    performers=new char[strlen(d.performers)+1];
    strcpy(performers, d.performers);
    label=new char[strlen(d.label)+1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;

}
Cd::~Cd()
{
    delete [] performers;
    delete [] label;
}
void Cd::Report() const
{
    cout << "Performer: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "Selection: " << selections << endl;
    cout << "Playtime: " << playtime << endl;
}
Classic::Classic(const char *s1, const char *s3, const char *s4, int n, double x) : Cd(s3, s4, n, x)
{
    work=new char[strlen(s1)+1];
    strcpy(work, s1);
}
Classic::Classic(const Cd &c, const char *s1) : Cd(c)
{
    work=new char[strlen(s1)+1];
    strcpy(work, s1);
}
Classic::Classic(const Classic & c)
{
    work=new char[strlen(c.work)+1];
    strcpy(work, c.work);
}
Classic::Classic()
{
    work=NULL;
}
Classic::~Classic()
{
    delete []work;
}
Classic & Classic::operator=(Classic & c)
{
    if (this==&c)
    return *this;
    delete [] work;
    Cd::operator=(c);
    work=new char[strlen(c.work)+1];
    strcpy(work, c.work);
    return *this;
}
void Classic::Report() const
{
    Cd::Report();
    cout << "Work : " << work << endl;
}
void Bravo(const Cd &disk)
{
    disk.Report();
}