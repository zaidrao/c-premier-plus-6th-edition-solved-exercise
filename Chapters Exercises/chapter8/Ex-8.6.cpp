#include "iostream"

template <typename T>
 T maxn(T[], int);

template <> const char* maxn(const char *[],int);
using namespace std; 
int main()
{
	int arri[6]={34,63,727,26,27,867};
	double arrd[4]={34,63,26,27};
	const char* strr[] = {"One", "TwoTwo", "ThreeThreeThree", "ThreeThreeThree", "FourFour"};
	int maxi;
	double maxd;
	const char *ps;
	maxi=maxn(arri,6);
	maxd=maxn(arrd,4);
	ps=maxn(strr,5);
	cout<<"Max int: "<<maxi<<endl;
	cout<<"Max double: "<<maxd<<endl;
	cout<<"Max string: "<<ps<<endl;
}
template <typename T>
T maxn( T ar[],int n)
{
    T temp= ar[0];
    for(int i=1;i<n;i++)
    {
        if(ar[i]>temp)
        temp=ar[i];
    }
    return temp;
}
template <> const char* maxn(const char *ar[],int n)
{
   const char *ch= ar[0];
     for(int i=1;i<n;i++)
    {
        if(strlen(ar[i])>strlen(ch))
        ch=ar[i];
    }
    return ch; 
}