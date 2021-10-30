#include "iostream"
#include "valarray"
template <class T1, class T2>
class Pair
{
  private:
    T1 a;
    T2 b;

  public:
    T1 &first();
    T2 &second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval) {}
    Pair() {}
};

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
  private:
    std::string label; // win label
    int years;         // num of years
    PairArray pair;

  public:
    Wine() {}
    Wine(const char *l, int y, const int yr[], const int bot[]);
    Wine(const char *l, int y);
    void GetBottles();
    std::string &Label() { return label; }
    int sum();
    void Show() const;
};
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;
    Wine holding(lab, yrs); // store label, years, give arrays yrs elements
    holding.GetBottles();   // solicit input for year, bottle count
    holding.Show();         // display object contents
    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72}; // create new object, initialize using data in arrays y and b
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    cout << "Total bottles for " << more.Label() // use Label() method
         << ": " << more.sum() << endl;          // use sum() method
    cout << "Bye\n";
    return 0;
}

Wine::Wine(const char *l, int y, const int yr[], const int bot[])
{
    label = l;
    years = y;
    pair = PairArray(ArrayInt(yr, y), ArrayInt(bot, y));
}
Wine::Wine(const char *l, int y)
{
    label = l;
    years = y;
    pair = PairArray(ArrayInt(y), ArrayInt(y));
}
void Wine::GetBottles()
{
    std::cout << "Enter Gully Wash data for " << years << " year(s):\n";
    for (int i = 0; i < years; i++)
    {
        std::cout << "Enter year: ";
        std::cin >> pair.first()[i];
        std::cout << "Enter bottles for that year: ";
        std::cin >> pair.second()[i];
    }
}

int Wine::sum()
{
    return pair.second().sum();
}

void Wine::Show() const
{
    using std::cout;
    using std::endl;
    cout << "Wine: " << label << endl;
    for (int i = 0; i < years; i++)
    {
        cout << "\t" << pair.first()[i]<<
        cout.width(5)<<
        pair.second()[i] << endl;
    }
}
template <class T1, class T2>
T1 &Pair<T1, T2>::first()
{
    return a;
}
template <class T1, class T2>
T2 &Pair<T1, T2>::second()
{
    return b;
}