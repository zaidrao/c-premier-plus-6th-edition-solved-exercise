#include "iostream"
#include "cmath" // for power function

using namespace std;

int main()
{
    const int InchesToFeet = 12;
    const double InchesToMeter = 0.0254;
    const double PoundToKilo = 2.2;

    int feet, inche, pound;
    double hight, wight;
    cout << "Enter Hight in Feets and Inches:\n";
    cout << "Feets : ";
    cin >> feet;
    cout << "Inches : ";
    cin >> inche;
    cout << "Enter wight in pound : ";
    cin >> pound;
    hight = feet * InchesToFeet + inche;
    hight = hight * InchesToMeter;
    hight = pow(hight, 2);
    wight = pound / PoundToKilo;
    cout << "\nBMI : " << (wight / hight);
}