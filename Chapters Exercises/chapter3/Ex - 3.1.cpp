#include "iostream"

using namespace std;

int main()
{
    const int c_fector = 12;
    int hight, inche;
    cout << "Enter Hight in Inches: ___\b\b\b";
    cin >> hight;
    inche = hight % c_fector;
    cout << endl
         << hight / c_fector << " feets " << inche << " inches.";
}