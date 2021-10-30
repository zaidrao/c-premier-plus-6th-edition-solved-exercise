// emp.h -- header file for abstr_emp class and children
#include <iostream>
#include <string>
#include <fstream>
class abstr_emp
{
  private:
    std::string fname; // abstr_emp's first name
    std::string lname; // abstr_emp's last name
    std::string job;

  public:
    abstr_emp() {}
    abstr_emp(const std::string &fn, const std::string &ln, const std::string &j) : fname(fn), lname(ln), job(j) {}
    virtual void ShowAll() const;                                          // labels and shows all data
    virtual void SetAll();                                                 // prompts user for values
	virtual void writeAll(std::ostream &o); // write file
	virtual void getAll(std::istream &in);
    friend std::ostream &operator<<(std::ostream &os, const abstr_emp &e); // just displays first and last name
    virtual ~abstr_emp() = 0;                                              // virtual base class
};

class employee : public abstr_emp
{
  public:
    employee(){};
    employee(const std::string &fn, const std::string &ln, const std::string &j) : abstr_emp(fn, ln, j) {}
    virtual void ShowAll() const;
    virtual void SetAll();
    void writeAll(std::ostream &o);
    void getAll(std::istream &in);
};

class manager : virtual public abstr_emp
{
  private:
    int inchargeof; // number of abstr_emps managed
  protected:
    int InChargeOf() const { return inchargeof; } // output
    int &InChargeOf() { return inchargeof; }      // input
  public:
    manager(){};
    manager(const std::string &fn, const std::string &ln, const std::string &j, int ico = 0) : abstr_emp(fn, ln, j), inchargeof(ico) {}
    manager(const abstr_emp &e, int ico) : abstr_emp(e), inchargeof(ico) {}
    virtual void ShowAll() const;
    virtual void SetAll();
    void writeAll(std::ostream &o);
    void getAll(std::istream &in);
};

class fink : virtual public abstr_emp
{
  private:
    std::string reportsto; // to whom fink reports
  protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string &ReportsTo() { return reportsto; }

  public:
    fink() {}
    fink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo) : abstr_emp(fn, ln, j), reportsto(rpo) {}
    fink(const abstr_emp &e, const std::string &rpo) : abstr_emp(e), reportsto(rpo) {}
    virtual void ShowAll() const;
    virtual void SetAll();
    void writeAll(std::ostream &o);
    void getAll(std::istream &in);
    
};

class highfink : public manager, public fink // management fink
{
  public:
    highfink() {}
    highfink(const std::string &fn, const std::string &ln, const std::string &j, const std::string &rpo, int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}
    highfink(const abstr_emp &e, const std::string &rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo) {}
    highfink(const manager &m, int ico) : abstr_emp(m), manager(m, ico) {}
    highfink(const fink &f, const std::string &rpo) : abstr_emp(f), fink(f, rpo) {}
    virtual void ShowAll() const;
    virtual void SetAll();
    void writeAll(std::ostream &o);
    void getAll(std::istream &in);
};

using namespace std;
inline void eatline()
{
	while (std::cin.get() != '\n')
		continue;
}
const int MAX = 10;
const char *file = "employees.dat";
void readFile(istream &in);
int main()
{
	
	// we can not use employee * pc[MAX]; because employee class is not a base class for other classes so here we use base class pointer
	abstr_emp * pc[MAX];
	// first check if file available or not
	ifstream in(file);
	if(in.is_open())
	{
		cout<<"Here is content of file";
		readFile(in);
	}
	else if(in.failbit)
	{
		// if file not found we do nothing just let program to run next
	}
	else
	{
		cout<<"could not open input file";
		exit(EXIT_FAILURE);
	}
	ofstream out(file, ios_base::out | ios_base::app);
	if(!out.is_open())
	{
		cout<<"could not open output file";
		exit(EXIT_FAILURE);
	}
	cout<<"\nInput new content in file\n";
	cout<<"Create field of (q for quit):"<<endl;
	cout<<"1: Employee\t2: Manager\n"
	      <<"3: Fink \t4: HighFink\n";
	int choice;
	int max=0;
	while (max < MAX && cin>>choice)
	{
		eatline();
		switch (choice)
		{
			case 1:
			pc[max] = new employee;
			pc[max]->SetAll();
			max++;
			break;
			case 2:
			pc[max] = new manager;
			pc[max]->SetAll();
			max++;
			break;
			case 3:
			pc[max] = new fink;
			pc[max]->SetAll();
			max++;
			break;
			case 4:
			pc[max] = new highfink;
			pc[max]->SetAll();
			max++;
			break;
			default:
			cout<<"Enter valid choice: ";
			continue;
		}
		cout<<"Enter choice (q for quit): ";
	}
	for(int i =0; i<max ; i++)
	{
		pc[i] -> writeAll(out);
		pc[i]->ShowAll();
	}
}
void readFile(istream &in)
{
	int classtype;
	int max=0;
	abstr_emp * pc[MAX]; // remember it only get first 10 fields from file 
	while(max < MAX && (in >> classtype))
	{
		in.get();
		switch (classtype)
		{
			case 1:
			pc[max] = new employee;
			pc[max]->getAll(in);
			max++;
			break;
			case 2:
			pc[max] = new manager;
			pc[max]->getAll(in);
			max++;
			break;
			case 3:
			pc[max] = new fink;
			pc[max]->getAll(in);
			max++;
			break;
			case 4:
			pc[max] = new highfink;
			pc[max]->getAll(in);
			max++;
			break;
		}
	}
	for(int i =0; i<max ; i++)
	{
		pc[i]->ShowAll();
	}
}
// implementation file
// abstr_emp methods

void abstr_emp::ShowAll() const
{
    cout << "First name: " << fname << endl;
    cout << "Last name: " << lname << endl;
    cout << "Job title: " << job << endl;
}
void abstr_emp::SetAll()
{
    cout << "Enter First name: ";
    getline(cin, fname);
    cout << "Enter Last name: ";
    getline(cin, lname);
    cout << "Enter Job title: ";
    getline(cin, job);
}
std::ostream &operator<<(std::ostream &os, const abstr_emp &e)
{
    os << "First name: " << e.fname << endl;
    os << "Last name: " << e.lname << endl;
    return os;
}
abstr_emp::~abstr_emp() {}

void abstr_emp::writeAll(std::ostream &o)
{
	o << fname << endl;
    o << lname << endl;
    o << job << endl;
}
void abstr_emp::getAll(std::istream &in)
{
	getline(in, fname);
    getline(in, lname);
    getline(in, job);
}

// employee methods

void employee::ShowAll() const
{
    cout << "\nEmployee Data:\n";
    abstr_emp::ShowAll();
}
void employee::SetAll()
{
    cout << "Input Employee Data:\n";
    abstr_emp::SetAll();
}
void employee::writeAll(std::ostream &o)
{
	o << "1"<<endl;
    abstr_emp::writeAll(o);
}
void employee::getAll(std::istream &in)
{
	abstr_emp::getAll(in);
}
// manger methods

void manager::ShowAll() const
{
    cout << "\nManager Data:\n";
    abstr_emp::ShowAll();
    cout << "Manger of " << manager::InChargeOf() << " employees." << endl;
}
void manager::SetAll()
{
    cout << "Input Manager Data:\n";
    abstr_emp::SetAll();
    cout << "Incharge of: ";
    cin >> InChargeOf();
}
void manager::writeAll(std::ostream &o)
{
	o << "2"<<endl;
    abstr_emp::writeAll(o);
    o <<manager::InChargeOf()<< endl;
}
void manager::getAll(std::istream &in)
{
	abstr_emp::getAll(in);
	(in >> InChargeOf()).get();
}
// fink methods

void fink::ShowAll() const
{
    cout << "\nFink Data:\n";
    abstr_emp::ShowAll();
    cout << "Fink reports to: " << ReportsTo() << endl;
}
void fink::SetAll()
{
    cout << "Input Fink Data:\n";
    abstr_emp::SetAll();
    cout << "Fink reports to: ";
    getline(cin, ReportsTo());
}
void fink::writeAll(std::ostream &o)
{
	o << "3"<<endl;
    abstr_emp::writeAll(o);
    o << ReportsTo() << endl;
}
void fink::getAll(std::istream &in)
{
	abstr_emp::getAll(in);
	getline(in, ReportsTo());
}
// finkhigh methods
void highfink::ShowAll() const
{
    cout << "\nHighFink Data:\n";
    abstr_emp::ShowAll();
    cout << "Manger of " << manager::InChargeOf() << " employees." << endl;
    cout << "Fink reports to: " << ReportsTo() << endl;
}
void highfink::SetAll()
{
    cout << "Input HighFink Data:\n";
    abstr_emp::SetAll();
    cout << "Incharge of: ";
    cin >> InChargeOf();
    cin.get();
    cout << "Fink reports to: ";
    getline(cin, ReportsTo());
}
void highfink::writeAll(std::ostream &o)
{
	o << "4"<<endl;
    abstr_emp::writeAll(o);
    o << manager::InChargeOf()<< endl;
    o << ReportsTo() << endl;
}
void highfink::getAll(std::istream &in)
{
	abstr_emp::getAll(in);
	(in >> InChargeOf()).get();
	getline(in, ReportsTo());
}