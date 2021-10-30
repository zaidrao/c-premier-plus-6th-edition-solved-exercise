#include "iostream"
#include <cstring>

class Stock
{
  private:
    char * company;
    long shares;
    double share_val;
    double total_val;
    void set_tot()
    {
        total_val = shares * share_val;
    }

  public:    // two constructors
    Stock(); // default constructor
    Stock(const char * co, long n = 0, double pr = 0.0);
    Stock(const Stock & ct);
    ~Stock(); // noisy destructor
    Stock &operator=(const Stock &);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};

int main()
{
    {
        using std::cout;
        cout << "Using constructors to create new objects\n";
        Stock stock1("NanoSmart", 12, 20.0); // syntax 1
        stock1.show();
        Stock stock2 = Stock("Boffo Objects", 2, 2.0); // syntax 2
        stock2.show();
        cout << "Assigning stock1 to stock2:\n";
        stock2 = stock1;
        cout << "Listing stock1 and stock2:\n";
        stock1.show();
        stock2.show();
        cout << "Using a constructor to reset an object\n";
        stock1 = Stock("Nifty Foods", 10, 50.0); // temp object
        cout << "Revised stock1:\n";
        stock1.show();
        cout << "Done\n";
    }
    return 0;
}
Stock::Stock() // default constructor
{
    std::cout << "Default constructor called\n";
    company=new char [5];
    strcpy(company,"No");
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}
Stock::Stock(const char*co, long n, double pr)
{
    std::cout << "Constructor using " << co << " called\n";
    company = new char[strlen(co)+1];
    strcpy(company,co);
    if (n < 0)
    {
        std::cout << "Number of shares can’t be negative; " << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
} // class destructor
Stock::Stock(const Stock & ct)
{
    company=new char[strlen(ct.company)+1];
    strcpy(company,ct.company);
    shares = ct.shares;
    share_val = ct.share_val;
    total_val = ct.total_val;
    
}
Stock::~Stock() // verbose class destructor
{
    std::cout << "Bye, " << company << "!\n";
    delete [] company;
}
Stock & Stock::operator=(const Stock & st)
{
    if (this == &st)
        return *this;
    delete[] company;
    company = new char[strlen(st.company)+1];
    std::strcpy(company, st.company);
    shares = st.shares;
    share_val = st.share_val;
    total_val = st.total_val;
    return *this;
}
void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can’t be negative. "
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}
void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can’t be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can’t sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}
void Stock::update(double price)
{
    share_val = price;
    set_tot();
}
void Stock::show()
{
    using std::cout;
    using std::ios_base; // set format to #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    cout << "Company: " << company
         << "  Shares: " << shares << '\n';
    cout << "  Share Price: $" << share_val; // set format to #.##
    cout.precision(2);
    cout << "  Total Worth: $" << total_val << '\n'; // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}
