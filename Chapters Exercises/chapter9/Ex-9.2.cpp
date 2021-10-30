#include "iostream"

using namespace std;
void strcount(const string);
 
int main()
{
	string na;
	cout << "Enter a line:\n";
    getline(cin,na);
    while (cin)
    {
       if(!na[0])
       break;
       strcount(na);
       cout << "Enter next line (empty line to quit):\n";
       getline(cin,na);
    }
    cout << "Bye\n";
    return 0;
}
void strcount(const string str)
{
    using namespace std;
    static int total = 0;
    int count = 0;
    cout << "\"" << str <<"\" contains ";
    int i=0;
    while (str[i++])
    count++;
    total += count;
    cout << count << " characters\n";
    cout << total << " characters total\n"; }