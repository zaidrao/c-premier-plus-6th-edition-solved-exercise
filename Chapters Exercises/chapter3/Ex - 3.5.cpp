#include "iostream"

using namespace std;

int main()
{
    cout << "Enter the world's population: ";
    long double WorldPap;
    cin >> WorldPap;
    cout << "Enter the world's population of US: ";
    long double USPap;
    cin >> USPap;
    cout << "The population of the US is " << (USPap / WorldPap) * 100 << "% of the world population.";
}