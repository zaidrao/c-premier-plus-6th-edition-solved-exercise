#include "iostream"

using namespace std;

int main()
{
    const float KmToMile = 62.14;
    const float LiterToG = 3.875;
    cout << "Enter the gasoline consumption in liter/100km: ";
    double LKm, mpg;
    cin >> LKm;
    mpg = LKm / LiterToG;
    mpg = KmToMile / mpg;
    cout << LKm << " L/100KM is " << mpg << " mpg.";
}