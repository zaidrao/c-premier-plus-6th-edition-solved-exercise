#include "iostream"

using namespace std;

int main()
{
    cout << "Enter the distance of your car travel in kilometres: ";
    double Km;
    cin >> Km;
    cout << "Enter the petrol your car used in liters: ";
    double liter;
    cin >> liter;
    cout << "Your car used " << (liter/Km) << " litters of petrol on each Km";
}