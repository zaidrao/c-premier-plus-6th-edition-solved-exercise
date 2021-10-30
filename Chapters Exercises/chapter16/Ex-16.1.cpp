#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string &str)
{
	string::reverse_iterator pe = str.rbegin();
	string::reverse_iterator pf = str.rend();
	pf--; //reverse decriment because pf pointing (-1) index
	for(int i = 0;i<str.size()/2;i++)
	{
		
		if(*pe != *pf)
		{
		return false;
		}
		pf--;
		pe++;
	}
	return true;
}
// also have another method reverse the string and compare both original and reverse. if both same then string are palindrome
int main()
{
	string a = "assaaaassa";
	if(isPalindrome(a))
	cout<<"yes";
	
}