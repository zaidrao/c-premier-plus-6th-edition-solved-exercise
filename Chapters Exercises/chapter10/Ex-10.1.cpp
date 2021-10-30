#include "iostream"
#include <cstring>

class BankAccount
{
    private:
    char name[40];
    char acctnum[25];  // or std::string acctnum; 
    double balance;
    public:
    BankAccount(const char * client="No Name", const char * num="No AccNum", double bal = 0.0); //or
    void show(void) const;
    void deposit(double cash);
    void withdraw(double cash); 
    };

using namespace std;
 
int main()
{
	BankAccount c1;
	c1.show();
	BankAccount c2("Zaid","546IA6",63663);
	c2.show();
	c1=BankAccount("Rao","YU6567");
	c1.deposit(3633);
	c2.withdraw(353);
	c1.show();
	c2.show();
	c1.withdraw(636366);
	c2.deposit(-36);
	c1.show();
	c2.show();
	
	
}

BankAccount::BankAccount(const char * client, const char * num, double bal)
{
    strcpy(name,client);
    strcpy(acctnum,num);
    balance=bal;
    
}
void BankAccount::show(void) const
{
    cout<<name<<" : "<<acctnum<<" : "<<balance<<endl;
    
}
void BankAccount::deposit(double cash)
{
    if(cash>0)
    balance+=cash;
    else
    cout<<"Input error."<<endl;
}
void BankAccount::withdraw(double cash)
{
    if(balance>0 && cash<=balance)
    balance-=cash;
    else if(cash>balance)
    cout<<"Withdraw limit reached."<<endl;
    else
    cout<<"Balance insufficient.";
}