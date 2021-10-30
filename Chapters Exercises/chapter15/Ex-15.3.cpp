// exc_mean.h  -- modified exception classes for hmean(), gmean()
#include <iostream>
#include <exception> // for logic_error class

class excep : std:: logic_error
{
  private:
    double v1;
    double v2;

  public:
    excep(double a = 0, double b = 0, const char * s=  "") : logic_error(s), v1(a), v2(b) {}
    void mesg();
};
inline void excep::mesg()
{
    std::cout<<logic_error::what() << "(" << v1 << ", " << v2 << "): "
              << "invalid arguments.\n";
}

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
            z = gmean(x, y);
            cout << "Geometric mean of " << x << " and " << y << " is " << z<< endl;
            cout << "Enter next set of numbers <q to quit>: ";
        }                     // end of try block
        catch (excep &le) // start of catch block
        {
            le.mesg();
            break;
        }
    }
    cout << "Bye!\n";
    return 0;
}
double hmean(double a, double b)
{
    if (a == -b)
        throw excep(a, b, "hmean");
    return 2.0 * a * b / (a + b);
}
double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw excep(a, b, "gmean");
    return std::sqrt(a * b);
}