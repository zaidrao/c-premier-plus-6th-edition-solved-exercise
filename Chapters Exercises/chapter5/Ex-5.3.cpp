#include <iostream>
 
using namespace std;
 
int main()
{
int number;
int sum = 0;
 
do
{
cout << "Enter numbers: ";
cin >> number;
 
sum = sum + number;
cout << "Current sum is: " << sum << endl;
}
while (number != 0);
 
return 0;
}