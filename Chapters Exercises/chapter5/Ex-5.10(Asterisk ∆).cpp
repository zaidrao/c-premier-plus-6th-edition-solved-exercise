/* Every time when making asterisk pattern first consider row. Make first loop to identify how many rows in pattern and also make 1st loop in ascending wise means assign 0 to loop variable and incriment till it reache to condition. 2nd loop for putting asterisk in pattern. If u want to ascending wise asterisk then in 2nd loop use this condition j<(i+1) for end 2nd loop. Here i is veriable used in 1st loop and j in 2nd loop. If u want descending wise asterisk then just assign row value to 2nd loop variable and make this condition j>i and update expression with j--.
if you want put space or or dots between empty space in asterisk u should be make another loop in 1st but befor asterisk loop we name it filling loop. For example if u want to achieve same output like in this program then filling loop should be descending wise and loop variable value always assign with ((row-1)-i)
row-1 because it fill every line till 1 value smaller tha row value.
if u want this ∆ type pattern then u should add 2 asterisk gap after every line means if first row have 1 asterisk then 2nd row should be 3 asterisk, 3rd row 5 asterisk and so on.

*/

#include "iostream"

using namespace std;
 
int main()
{
	int row;
	cout<<"Enter number of row: ";
	cin>>row;
	cout<<endl;
	for(int i=0;i<row;i++)
	{
	    for(int j=((row-1)-i);j>0;j--)
	    {
	        cout<<" ";
	    }
	    for(int j=0;j<((i+i)+1);j++)
	    {
	        cout<<"*";
	    }
	    cout<<endl;
	}
}