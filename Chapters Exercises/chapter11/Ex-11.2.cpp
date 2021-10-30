#include "iostream"
#include "cmath"
#include "cstdlib"
#include "ctime"

namespace VECTOR
{
class Vector
{
  public:
    enum Mode
    {
        RECT,
        POL
    }; // RECT for rectangular, POL for Polar modes
  private:
    double x;   // horizontal value
    double y;   // vertical value
    Mode mode;
    double set_mag();
    double set_ang();
    void set_x();
    void set_y();

  public:
    Vector();
    Vector(double n1, double n2, Mode form = RECT);
    ~Vector();
    double xval() const { return x; }     // report x value
    double yval() const { return y; }     // report y value
    double magval() { return set_mag(); } // report magnitude
    double angval() { return set_ang(); } // report angle
    void polar_mode();                    // set mode to POL
    void rect_mode();                     // set mode to RECT
                                          // operator overloading
    Vector operator+(const Vector &b) const;
    Vector operator-(const Vector &b) const;
    Vector operator-() const;         // inverse sign
    Vector operator*(double n) const; // friends
    friend Vector operator*(double n, const Vector &a);
    friend std::ostream &operator<<(std::ostream &os, Vector &v);
};
}

int main()
{
    using namespace std; 
    using VECTOR::Vector;
    srand(time(0)); // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step=Vector(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        cout << "After " << steps << " steps, the subject "
                                     "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n"
             << result << endl;
        cout << "Average outward distance per step = " << result.magval() / steps << endl;
        steps = 0;
        result=Vector(0.0, 0.0);
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}

using std::atan;
using std::atan2;
using std::cos;
using std::cout;
using std::sin;
using std::tan;
namespace VECTOR
{                                           // compute degrees in one radian
const double Rad_to_deg = 45.0 / atan(1.0); // should be about 57.2957795130823 // private methods // calculates magnitude from x and y
double Vector::set_mag()
{
    return sqrt(x * x + y * y);
}
double Vector::set_ang()
{
    if (x == 0.0 && y == 0.0)
        return 0.0;
    else
        return atan2(y, x);
} // set x from polar coordinate
Vector::Vector() // default constructor
{
    x = y = 0.0;
    mode = RECT;
} // construct vector from rectangular coordinates if form is r // (the default) or else from polar coordinates if form is p
Vector::Vector(double n1, double n2, Mode form)
{
    mode = form;
    if (form == RECT)
    {
        x = n1;
        y = n2;
    }
    else if (form == POL)
    {
        x = n1 * cos(n2/Rad_to_deg);
        y = n1 * sin(n2/Rad_to_deg);
    }
    else
    {
        cout << "Incorrect 3rd argument to Vector() -- ";
        cout << "vector set to 0\n";
        x = y = 0.0;
        mode = RECT;
    }
}
Vector::~Vector() // destructor
{
}
void Vector::polar_mode() // set to polar mode
{
    mode = POL;
}
void Vector::rect_mode() // set to rectangular mode
{
    mode = RECT;
}
// operator overloading
// add two Vectors
Vector Vector::operator+(const Vector & b) const
{
    Vector sum;
    sum.x = x + b.x;
    sum.y = y + b.y;
    return sum; 
}
// subtract Vector b from a
Vector Vector::operator-(const Vector &b) const
{
    return Vector(x - b.x, y - b.y);
}
// reverse sign of Vector
Vector Vector::operator-() const
{
    return Vector(-x, -y);
}
// multiply vector by n
Vector Vector::operator*(double n) const
{
    return Vector(n * x, n * y);
}
// friend methods // multiply n by Vector a
Vector operator*(double n, const Vector &a)
{
    return a * n;
}
// display rectangular coordinates if mode is RECT,
// else display polar coordinates if mode is POL
std::ostream &operator<<(std::ostream &os, Vector &v)
{
    if (v.mode == Vector::RECT)
        os << "(x,y) = (" << v.x << ", " << v.y << ")";
    else if (v.mode == Vector::POL)
    {
        os << "(m,a) = (" << v.magval() << ", " << v.angval() * Rad_to_deg << ")";
    }
    else
        os << "Vector object mode is invalid";
    return os;
}
}
