#include "iostream"
#include "cstring"
class Cd
{
    // represents a CD disk
  private:
    char performers[50];
    char label[20];
    int selections;  // number of selections
    double playtime; // playing time in minutes
  public:
    Cd(const char *s1, const char *s2, int n, double x);
    Cd();
    virtual ~Cd(){};
    virtual void Report() const; // reports all CD data
};
class Classic : public Cd
{
  private:
    char work[40];

  public:
    Classic(const char *s1, const char *s3, const char *s4, int n, double x);
    Classic(){};
    Classic(const Cd &c, const char *s1);
    virtual void Report() const;
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
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}
Cd::Cd()
{
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0;
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
    strcpy(work, s1);
}
Classic::Classic(const Cd &c, const char *s1) : Cd(c)
{
    strcpy(work, s1);
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