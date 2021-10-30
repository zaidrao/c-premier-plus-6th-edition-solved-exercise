#include "iostream"

using namespace std;

int main()
{
    const int SecToDay = 86400;
    const int SecToHour = 3600;
    const int secToMinut = 60;
    long long sec;
    int ForDay, ForHour, ForMinut,ForSec;
    cout << "Enter the number of seconds: ";
    cin >> sec;
    ForDay = sec / SecToDay;
    int remainder = sec % SecToDay;
    ForHour = remainder / SecToHour;
    remainder = remainder % SecToHour;
    ForMinut = remainder / secToMinut;
    ForSec = remainder % secToMinut;
    cout << sec << " seconds = " << ForDay << " Days, " << ForHour << " Hours, " << ForMinut << " Minutes, " << ForSec << " seconds.";
}