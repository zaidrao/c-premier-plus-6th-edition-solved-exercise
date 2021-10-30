#include "iostream"

using namespace std;

struct candy{
    string name;
    double Wight;
    int cal;
};

void fill(candy &, string na="Millennium Munch", double wi=2.85, int ca=350);
void show (const candy &);
 
int main()
{
	int cal;
	double wigh;
	char na[50];
	candy cand1;
	candy cand2;
	cout<<"Enter candy name: ";
	cin.get(na,50);
	cout<<"\nEnter candy Wight: ";
	cin>>wigh;
	cout<<"\nEnter candy calories: ";
	cin>>cal;
	fill(cand2,na,wigh,cal);
	show (cand2);
	fill(cand1);
	show(cand1);
	
}
void fill(candy & can, string na, double wi, int ca)
{
    can.name=na;
    can.Wight=wi;
    can.cal=ca;
    
}
void show (const candy & ca)
{
    cout<<ca.name<<": "<<ca.Wight<<": "<<ca.cal<<endl;
}