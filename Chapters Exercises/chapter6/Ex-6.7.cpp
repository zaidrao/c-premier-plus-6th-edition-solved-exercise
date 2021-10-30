#include "iostream"
#include "cctype"

using namespace std;
 
int main()
{
	char ch[20];
	int word=0,vo=0,con=0,oth=0;
	cout<<"Enter words (q to quit):"<<endl;
	cin>>ch;
	while(strcmp(ch, "q"))
	{
	    word++;
	    if (isalpha(ch[0]))
	    {
	        switch (ch[0])
	        {
	            case 'a':
	            case 'A':
	            vo++;
	            break;
	            case 'e':
	            case 'E':
	            vo++;
	            break;
	            case 'i':
	            case 'I':
	            vo++;
	            break;
	            case 'O':
	            case 'o':
	            vo++;
	            break;
	            case 'u':
	            case 'U':
	            vo++;
	            break;
	            default:
	            con++;
	            break;
	            
	        }
	    }
	    else
        oth++;
        cin>>ch;
	}
	cout<<"Total words: "<<word;
	cout<<endl<<vo<<" words beginning with vowels"<<endl;
	cout<<con<<" words beginning with consonants"<<endl;
	cout<<oth<<" Others";
}