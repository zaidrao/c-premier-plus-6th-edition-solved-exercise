#include "iostream"
#include "cstring"

using namespace std;

class Port
{
    private:
    char * brand;
    char style[20]; // i.e., tawny, ruby, vintage
    int bottles;
    public:
    Port(const char * br = "none", const char * st = "none", int b = 0);
    Port(const Port & p);                // copy constructor
    virtual ~Port() { delete [] brand; }
    Port & operator=(const Port & p);
    Port & operator+=(int b);            // adds b to bottles
    Port & operator-=(int b);            // subtracts b from bottles, if available
    int BottleCount() const { return bottles; }
    virtual void Show() const;
    friend ostream & operator<<(ostream & os, const Port & p);
};

class VintagePort : public Port // style necessarily = "vintage"
{
    private:
    char * nickname;           // i.e., "The Noble" or "Old Velvet", etc.
    int year;                  // vintage year
    public:
    VintagePort();
    VintagePort(const char * br, int b, const char * nn, int y);
    VintagePort(const VintagePort & vp);
    ~VintagePort() { delete [] nickname; }
    VintagePort & operator=(const VintagePort & vp);
    void Show() const;
    friend ostream & operator<<(ostream & os, const VintagePort & vp);
};

int main()
{
	Port p("Gallo","tawny", 20);
	Port p2("Gallo", "classic", 10);
	VintagePort vp("Yillo",15,"Vp yillo", 10);
	cout<<p<<endl;
	Port vp2;
	vp2=vp;
	vp.Show();
	vp2.Show();
}

Port::Port(const char * br, const char * st, int b)
{
    brand=new char[strlen(br)+1];
    strcpy(brand,br);
    strcpy(style,st);
    bottles=b;
}
Port::Port(const Port & p)
{
    brand=new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles=p.bottles;
}
Port & Port::operator=(const Port & p)
{
    if(this==&p)
    return *this;
    delete []brand;
    brand=new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles=p.bottles;
    return *this;
}
Port & Port::operator+=(int b)
{
    if(b>=0)
    bottles+=b;
    else
    cout<<"Invalid num";
    return *this;
}
Port & Port::operator-=(int b)
{
    if(b<=bottles)
    bottles-=b;
    else
    cout<<"Invalid num";
    return *this;
}
void Port::Show() const
{
    cout<<"Brand: "<<brand<<endl;
    cout<<"Style: "<<style<<endl;
    cout<<"Bottles: "<<bottles<<endl;
}
std::ostream &operator<<(std::ostream &os, const Port &p)
{
    os<< p.brand << ", " << p.style<<", "<<p.bottles;
    return os;
}

//VintagePort Methods
VintagePort::VintagePort():Port("","Vintage")
{
   nickname=nullptr;
   year=0;    
}
VintagePort::VintagePort(const char * br, int b, const char * nn, int y): Port(br,"Vintage",b)
{
    nickname=new char[strlen(br)+1];
    strcpy(nickname,nn);
    year=y;
}
VintagePort::VintagePort(const VintagePort & vp):Port(vp)
{
    nickname=new char[strlen(vp.nickname)+1];
    strcpy(nickname,vp.nickname);
    year=vp.year;
}
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if(this==&vp)
    return *this;
    delete []nickname;
    Port::operator=(vp);
    nickname=new char[strlen(vp.nickname)+1];
    strcpy(nickname,vp.nickname);
    year=vp.year;
    return *this;
}
void VintagePort::Show() const
{
    Port::Show();
    cout<<"Nickname: "<<nickname<<endl;
    cout<<"Year: "<<year<<endl;
}
ostream & operator<<(ostream & os, const VintagePort & vp)
{
    os<< ", " << vp.nickname<<", "<<vp.year;
    return os;
}