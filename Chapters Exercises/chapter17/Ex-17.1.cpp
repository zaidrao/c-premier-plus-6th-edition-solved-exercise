/*
Write a program that counts the number of characters up to the first  $ in input and that leaves the  $ in the input stream.
*/

#include <iostream>


int main()
{
	using namespace std;
	cout<<"Enter string: ";
	int count=0;
	char ch;
	while (cin.peek() != '$')
	{
		cin.get(ch);
		count++;
	}
	cin.get(ch);
	cout<<"Total characters: "<<count<<endl;
	cout<<"Last character: "<<ch;
	// u can also use cin.putback() 
}