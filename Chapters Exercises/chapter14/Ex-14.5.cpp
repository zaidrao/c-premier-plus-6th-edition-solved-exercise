// emp.h -- header file for abstr_emp class and children
#include <iostream>
#include <string>
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
    friend std::ostream &operator<<(std::ostream &os, const abstr_emp &e); // just displays first and last name
    virtual ~abstr_emp() = 0;                                              // virtual base class
};

class employee : public abstr_emp
{
  public:
    employee(){}
    employee(const std::string &fn, const std::string &ln, const std::string &j) : abstr_emp(fn, ln, j) {}
    virtual void ShowAll() const;
    virtual void SetAll();
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
};

using namespace std;

int main(void)
{
    employee em("Trip", "Harris", "Thumper");
    cout << em << endl;
    em.ShowAll();
    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    cout<<endl << ma << endl;
    ma.ShowAll();
    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    cout<<endl << fi << endl;
    fi.ShowAll();
    highfink hf(fi, "Curly Kew"); // recruitment?
    cout<<endl;
    hf.ShowAll();
    cout << "Press a key for next phase:\n";
    cin.get();
    highfink hf2;
    hf2.SetAll();
    cout << "Using an abstr_emp * pointer:\n";
    abstr_emp *tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; i++)
        tri[i]->ShowAll();
    return 0;
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