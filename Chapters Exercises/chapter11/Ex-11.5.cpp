#include "iostream"

class Stonewt
{
  public:
    enum Mode
    {
        STN,IP,FP
    };
  private:
    enum
    {
        Lbs_per_stn = 14
    };               // pounds per stone
    int stone;       // whole stones
    double pds_left; // fractional pounds
    double pounds;   // entire weight in pounds
    Mode form;
  public:
    Stonewt(double lbs);          // constructor for double pounds
    Stonewt(int stn, double lbs,Mode f=STN); // constructor for stone, lbs
    void m_stn(){form=STN;}
    void m_ip(){form=IP;}
    void m_fp(){form=FP;}
    Stonewt();                    // default constructor
    ~Stonewt();
    Stonewt operator+(const Stonewt &t) const;
    Stonewt operator-(const Stonewt &t) const;
    Stonewt operator*(double n) const;
    friend Stonewt operator*(double m, const Stonewt &t) { return t * m; } // inline definition
    friend std::ostream &operator<<(std::ostream &os, const Stonewt &t);
};

using std::cout;
using std::endl;
int main()
{
    Stonewt incognito = 275; // uses constructor to initialize
    Stonewt wolfe(285.7);    // same as Stonewt wolfe = 285.7;
    Stonewt taft(21, 8);
    incognito.m_stn();
    cout << "The celebrity weighed "<<incognito;
    wolfe.m_stn();
    cout << "The detective weighed "<<wolfe;
    taft.m_fp();
    cout << "The President weighed "<<taft;
    incognito = 276.8*4; // uses constructor for conversion
    taft = taft+23;        // same as taft = Stonewt(325);
    cout << "After dinner, the celebrity weighed "<<incognito;
    taft.m_ip();
    cout << "After dinner, the President weighed "<<taft;
}

Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn; // integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    form = FP;
} // construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs,Mode f)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    form=f;
}
Stonewt::Stonewt() // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
    form=STN;
}
Stonewt::~Stonewt() // destructor
{
}
Stonewt Stonewt::operator+(const Stonewt &t) const
{
    return Stonewt(pounds+t.pounds);
}
Stonewt Stonewt::operator-(const Stonewt &t) const
{
    return Stonewt(pounds-t.pounds);
}
Stonewt Stonewt::operator*(double n) const
{
    return Stonewt(pounds*n);
}
std::ostream &operator<<(std::ostream &os, const Stonewt &t)
{
    if(t.form==Stonewt::STN)
    os << t.stone << " stone, " << t.pds_left << " pounds\n";
    else if(t.form==Stonewt::FP)
    cout << t.pounds << " floting pounds\n";
    else if(t.form==Stonewt::IP)
    cout << int(t.pounds+0.5) << " integer pounds\n";
    else
    cout <<" Unknown form\n";
    return os; 
}