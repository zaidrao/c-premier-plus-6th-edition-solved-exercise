#include "iostream"
#include "string"

using namespace std;

const int Seasons = 4;
const string Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

struct expen{
    double mem[Seasons];
};
void fill(expen *);
void show(expen);
 
int main()
{
    expen ex;
	fill(&ex);
	show(ex);	
}
void fill(expen *exp)
{
    for (int i = 0; i < Seasons; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >>exp->mem[i]; // also use (*exp).mem[i]; 
    }
}
void show(expen ex)
{ 
    double total = 0.0;
    cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << ex.mem[i] << endl;
        total += ex.mem[i]; 
    }
        cout << "Total Expenses: $" << total << endl;

}