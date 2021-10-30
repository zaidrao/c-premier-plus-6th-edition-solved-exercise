#include "iostream"

class Stonewt
{
  private:
    enum
    {
        Lbs_per_stn = 14
    };               // pounds per stone
    int stone;       // whole stones
    double pds_left; // fractional pounds
    double pounds;   // entire weight in pounds
  public:
    Stonewt(double lbs);          // constructor for double pounds
    Stonewt(int stn, double lbs); // constructor for stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    bool operator>(const Stonewt &t) const;
    bool operator<(const Stonewt &t) const;
    bool operator>=(const Stonewt &t) const;
    bool operator<=(const Stonewt &t) const;
    bool operator==(const Stonewt &t) const;
    bool operator!=(const Stonewt &t) const;
    double r_poun(){return pounds;}
    void show_lbs() const; // show weight in pounds format
    void show_stn() const; // show weight in stone format
};

void display(const Stonewt &st, int n);
using std::cout;
using std::endl;
using std::cin;
int main()
{
    const int lim=6;
    Stonewt test(11,0);
    Stonewt arr[lim]{{2,134},{534},{16}};
    Stonewt s=arr[0];
    Stonewt m=arr[0];
    int equal=0,great=0;
    for(int i=0;i<lim;i++)
    {
        if(arr[i].r_poun()==0)
        {
            double lb;
            cout<<"Enter lbs: ";
            cin>>lb;
            arr[i]=Stonewt(lb);
        }
        if(arr[i]<s)
        s=arr[i];
        if(arr[i]>m)
        m=arr[i];
        if(arr[i]==test)
        equal++;
        if(arr[i]>test)
        great++;
        
    }
    cout<<"Largest element ";m.show_lbs();
    cout<<"\nSmallest element ";s.show_lbs();
    cout<<endl<<great<<" elements greater than 11 stone";
    cout<<endl<<equal<<" elements equal to 11 stone";
    
}

Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn; // integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
} // construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}
Stonewt::Stonewt() // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
}
Stonewt::~Stonewt() // destructor
{
}
void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
} // show weight in pounds
void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}
bool Stonewt::operator>(const Stonewt &t) const
{
    return pounds>t.pounds; 
}
bool Stonewt::operator<(const Stonewt &t) const
{
    return pounds<t.pounds; 
}
bool Stonewt::operator>=(const Stonewt &t) const
{
    return pounds>=t.pounds; 
}
bool Stonewt::operator<=(const Stonewt &t) const
{
    return pounds<=t.pounds; 
}
bool Stonewt::operator==(const Stonewt &t) const
{
    return pounds==t.pounds; 
}
bool Stonewt::operator!=(const Stonewt &t) const
{
    return pounds!=t.pounds; 
}