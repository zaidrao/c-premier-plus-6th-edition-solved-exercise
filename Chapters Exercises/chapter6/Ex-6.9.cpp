#include "iostream"
#include "fstream"
#include "cstdlib" // for exit()

using namespace std;

struct monetary
{
    string name;
    double amount;
};

int main()
{
    ifstream in;
	in.open("cont.txt");
	if (!in.is_open())
	{
	    cout<<"File not open";
	    exit(EXIT_FAILURE);
	}
    cout << "How many members participate: ";
    int mem;
    in >> mem;
    monetary *pc = new monetary[mem];
    for (int i = 0; i < mem; i++)
    {
        cout << "Member name: ";
        getline(in,pc[i].name);
        cout << "Member amount: ";
        in >> pc[i].amount;
    }
    cout << endl;
    int Gpa = 0, Pa = 0;
    for (int i = 0; i < mem; i++)
    {
        if (pc[i].amount >= 10000)
            Gpa++;
        else if(pc[i].amount < 10000)
            Pa++;
    }
    monetary *gpa = new monetary[Gpa];
    monetary *pa = new monetary[Pa];
    int g=0,p=0;
    for (int i = 0; i < mem; i++)
    {
        if (pc[i].amount >= 10000)
        {
            gpa[g].name = pc[i].name;
            gpa[g].amount = pc[i].amount;
            g++;
        }
        else if(pc[i].amount < 10000)
        {
            pa[p].name = pc[i].name;
            pa[p].amount = pc[i].amount;
            p++;
        }
    }
    
    if (Gpa != 0)
    {
        cout << "Grand Patrons:" << endl;
        for (int i = 0; i < Gpa; i++)
            cout << gpa[i].name << " $" << gpa[i].amount << endl;
    }
    else
        cout << "Grand Patrons:\nnone\n";
    if (Pa != 0)
    {
        cout << "Patrons:" << endl;
        for (int i = 0; i < Pa; i++)
            cout << pa[i].name << " $" << pa[i].amount << endl;
    }
    else
        cout << "Patrons:\nnone\n";
}