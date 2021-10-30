// exc_mean.h  -- modified exception classes for hmean(), gmean()
#include <iostream>
#include <exception> // for exception class

class bad_hmean : public std::exception
{
  public:
    bad_hmean(){}
    const char* what() const throw(){return  "bad arguments to hmean()\n";}
};
class bad_gmean: public std::exception
{
  public:
    bad_gmean(){}
    const char* what() const throw(){return  "bad arguments to gmean()\n";}
};

//– using exception classes
#include <cmath>

double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    double x, y, z;
    cout << "Enter two numbers: ";
    while (cin >> x >> y)
    {
        try
        { // start of try block
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }                     // end of try block
        catch (bad_hmean &bg) // start of catch block
        {
            cout<<bg.what();
            cout << "Try again.\n";
            continue;
        }
        catch (bad_gmean &hg)
        {
            cout << hg.what();
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // end of catch block
    }
    cout << "Bye!\n";
    return 0;
}
double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean();
    return 2.0 * a * b / (a + b);
}
double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean();
    return std::sqrt(a * b);
}