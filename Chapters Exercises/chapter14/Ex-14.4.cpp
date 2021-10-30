#include "iostream"
#include "ctime"
#include "cstdlib"
// Header file - classes declaration
class Person
{
  private:
    std::string firstName;
    std::string lastName;

  protected:
    void get() const;
    void set();

  public:
    Person() : firstName("None"), lastName("None") {}
    Person(const char *f,const char *l) : firstName(f), lastName(l) {}
    Person(const std::string &f,const std::string& l) : firstName(f), lastName(l) {}
    virtual ~Person(){};
    virtual void show() const;
    virtual void input();
};
class Gunslinger : virtual public Person
{
  private:
    int noches;

  protected:
    void get() const;
    void set();

  public:
    Gunslinger(int n = 0) : noches(n) {}
    virtual double draw() const { return 25; } // return any draw value. u can also use rand()
    void show() const;
    void input();
};
class PokerPlayer : virtual public Person
{
  public:
    PokerPlayer() {}
    void input();
    virtual int draw() const;
};
class BadDude : public Gunslinger, public PokerPlayer
{
  public:
    BadDude() {}
    void input();
    void show() const;
    double gdraw() const { return Gunslinger::draw(); }
    int cdraw() const { return PokerPlayer::draw(); }
};
using namespace std;

const int SIZE = 5;
int main()
{
    // simple program just for testing, same as listing 14.12
    // u can try ur own
    Person *lolas[SIZE];
    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the Person's category:\n"
             << "p: Person\ng: Gunslinger\n"
             << "o: PokerPlayer\nb: BadDude\nq: quit\n";
        cin >> choice;
        while (strchr("pgobq", choice) == NULL)
        {
            cout << "Please enter p, g, o, b, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'p':
            lolas[ct] = new Person;
            break;
        case 'g':
            lolas[ct] = new Gunslinger;
            break;
        case 'o':
            lolas[ct] = new PokerPlayer;
            break;
            case 'b':
            lolas[ct] = new BadDude;
            break;
        }
        cin.get();
        lolas[ct]->input();
    }
    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas[i]->show();
    }
    for (i = 0; i < ct; i++)
        delete lolas[i];
    cout << "Bye.\n";
    return 0;
}
// implementation file
// Person methods
void Person::get() const
{
    cout << "First name: " << firstName << endl;
    cout << "Last name: " << lastName << endl;
}
void Person::set()
{
    cout << "Enter First name: ";
    getline(cin, firstName);
    cout << "Enter Last name: ";
    getline(cin, lastName);
}
void Person::show() const
{
    cout << "Person Data:\n";
    Person::get();
}
void Person::input()
{
    cout << "Input Person Data:\n";
    Person::set();
}
// Gunslinger methods
void Gunslinger::get() const
{
    cout << "Gun noches: " << noches<<endl;
}
void Gunslinger::set()
{
    cout << "Gun noches: ";
    cin >> noches;
}
void Gunslinger::show() const
{
    cout << "Gunslinger Data:\n";
    Person::get();
    Gunslinger::get();
    cout<<"Gunslinger Draw time: "<<Gunslinger::draw()<<endl;
}
void Gunslinger::input()
{
    cout << "Input Gunslinger Data:\n";
    Person::set();
    Gunslinger::set();
}
// PokerPlayer methods
void PokerPlayer::input()
{
    cout << "Input PokerPlayer Data:\n";
    Person::set();
}
int PokerPlayer::draw() const
{
    srand(time(0));
    int n = rand() % 52 + 1;
    return n;
}
// BadDude methods
void BadDude::input()
{
    cout << "Input BadDude Data:\n";
    Person::set();
    Gunslinger::set();
}
void BadDude::show() const
{
    cout << "BadDude Data:\n";
    Person::get();
    Gunslinger::get();
    cout<<"BadDude gun Draw time: "<<gdraw()<<endl;
    cout<<"BadDude Card Draw time: "<<cdraw()<<endl;
}