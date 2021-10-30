#include "iostream"

using namespace std;
 
int main()
{
	double dBalance = 100,  dOriginalBalance = 100, cBalance = 100;

int numYears = 0;

while (cBalance <= dBalance) {
numYears ++;

dBalance += (0.10 *  dOriginalBalance);
cBalance += (0.05 * cBalance);
}

cout << "Cleo's investment exceeds Daphne's investment after " <<  numYears << " years." << endl;
cout << "Cleo has $" << cBalance << " and Daphne has $" << dBalance << endl;
}