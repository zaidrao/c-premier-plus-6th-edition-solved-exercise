#include "iostream"

class complex
{
    private:
    double imag;
    double real;
    public:
    complex();
    complex(double re,double img);
    ~complex();
    complex operator+(const complex &c)const;
    complex operator-(const complex &c)const;
    complex operator*(const complex &c)const;
    complex operator~()const;
    friend complex operator*(double x,const complex &c);
    friend std::ostream & operator<<(std::ostream &os,const complex &c);
    friend std::istream & operator>>(std::istream &is, complex &c);
};
using std::cout;
using std::cin;

int main()
{
	complex a(3.0, 4.0);
	complex c;
	cout << "Enter a complex number (q to quit):\n";
	while (cin >> c)
	{
	    cout << "c is " << c << '\n';
	    cout << "complex conjugate is " << ~c << '\n';
	    cout << "a is " << a << "\n";
	    cout << "a + c is " << a + c << '\n';
	    cout << "a - c is " << a - c << '\n'; 
	    cout << "a * c is " << a * c << '\n';
	    cout << "2 * c is " << 2 * c << '\n';
	    cout << "Enter a complex number (q to quit):\n";
	}
	cout << "Done!\n";
}
complex::complex(double re,double img)
{
    real=re;
    imag=img;
}
complex::complex()
{
   real=imag=0; 
}
complex::~complex()
{
}
complex complex::operator+(const complex &c)const
{
   return complex(real+c.real, imag+c.imag); 
}
complex complex::operator-(const complex &c)const
{
   return complex(real-c.real, imag-c.imag); 
}
complex complex::operator*(const complex &c)const
{
   return complex((real*c.real-imag*c.imag), (real*c.real+imag*c.imag)); 
}
complex operator*(double x,const complex &c)
{
    return complex(x*c.real,x*c.imag);
}
complex complex::operator~()const
{
   return complex(real,-imag);
}
std::ostream & operator<<(std::ostream &os,const complex &c)
{
    os<<"("<<c.real<<","<<c.imag<<"i)";
    return os;
}
std::istream & operator>>(std::istream &is,complex &c)
{
    std::cout<<"real: ";
    if(is >> c.real)
    {
        std::cout << "imaginary: ";
        is >> c.imag;
    }
    return is;
}