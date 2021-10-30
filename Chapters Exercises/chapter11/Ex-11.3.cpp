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
    double mag; // length of vector
    double ang; // direction of vector in degrees
    Mode mode;
    void set_mag();
    void set_ang();
    void set_x();
    void set_y();

  public:
    Vector();
    Vector(double n1, double n2, Mode form = RECT);
    ~Vector();
    double xval() const { return x; }     // report x value
    double yval() const { return y; }     // report y value
    double magval() const { return mag; } // report magnitude
    double angval() const { return ang; } // report angle
    void polar_mode();                    // set mode to POL
    void rect_mode();                     // set mode to RECT
                                          // operator overloading
    Vector operator+(const Vector &b) const;
    Vector operator-(const Vector &b) const;
    Vector operator-() const;         // inverse sign
    Vector operator*(double n) const; // friends
    friend Vector operator*(double n, const Vector &a);
    friend std::ostream &operator<<(std::ostream &os, const Vector &v);
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
    double target;
    double dstep;
    int trail;
    unsigned long * pt;
    int maxS;
    int minS;
    int AveS;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;
            cout << "Enter Num of Trail: ";
        if (!(cin >> trail))
            break;
            pt=new unsigned long[trail];
       for(int i=0;i<trail;i++)
       {
        unsigned long steps = 0;
        result=Vector(0.0, 0.0);
        while (result.magval() < target)
        {
            direction = rand() % 360;
            step=Vector(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        pt[i]=steps;
       }
       unsigned long sum=0;
       maxS=0; minS=-1; AveS=0;
       for(int i=0;i<trail;i++)
       {
           if(pt[i]>maxS)
           maxS=pt[i];
           if(minS==-1||pt[i]<minS)
           minS=pt[i];
           sum=pt[i]+sum;
           
        
       }
        AveS=sum/trail;
        cout << "After " << trail << " trails, the subject has the following Result:\n";
        result.polar_mode();
        cout << result << endl;
        cout << "Total steps = " <<sum<<endl;
        cout << "Average steps = " <<AveS<<endl;
       cout << "Minimum steps = " << minS<< endl;
       cout << "Maximum steps = " << maxS<< endl;
        result=Vector(0.0, 0.0);
        delete []pt;
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
void Vector::set_mag()
{
    mag = sqrt(x * x + y * y);
}
void Vector::set_ang()
{
    if (x == 0.0 && y == 0.0)
        ang = 0.0;
    else
        ang = atan2(y, x);
} // set x from polar coordinate
void Vector::set_x()
{
    x = mag * cos(ang);
} // set y from polar coordinate
void Vector::set_y()
{
    y = mag * sin(ang);
}
Vector::Vector() // default constructor
{
    x = y = mag = ang = 0.0;
    mode = RECT;
} // construct vector from rectangular coordinates if form is r // (the default) or else from polar coordinates if form is p
Vector::Vector(double n1, double n2, Mode form)
{
    mode = form;
    if (form == RECT)
    {
        x = n1;
        y = n2;
        set_mag();
        set_ang();
    }
    else if (form == POL)
    {
        mag = n1;
        ang = n2 / Rad_to_deg;
        set_x();
        set_y();
    }
    else
    {
        cout << "Incorrect 3rd argument to Vector() -- ";
        cout << "vector set to 0\n";
        x = y = mag = ang = 0.0;
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
    sum.set_ang();
    sum.set_mag();
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
std::ostream &operator<<(std::ostream &os, const Vector &v)
{
    if (v.mode == Vector::RECT)
        os << "(x,y) = (" << v.x << ", " << v.y << ")";
    else if (v.mode == Vector::POL)
    {
        os << "(m,a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
    }
    else
        os << "Vector object mode is invalid";
    return os;
}
}
