#include <iostream>
#include <cctype>

using namespace std;

bool isPalindrome(string &str)
{
	string temp;
	for(int i = 0; i< str.length();i++)
	{
		if(!isspace(str[i]) && !ispunct(str[i]))
		{
			char c= tolower(str[i]);
			temp.append(&c);
		}
	}
	// reverse the string using constructor
	if(temp == string(temp.rbegin(),temp.rend()))
	{
		return true;
	}
	return false;	
}
int main()
{
	string g="Madam, I'm  Adam.";
	if(isPalindrome(g))
	cout<<"yes";
}