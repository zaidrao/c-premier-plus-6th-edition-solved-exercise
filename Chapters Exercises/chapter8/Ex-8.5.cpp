#include "iostream"

using namespace std;

template <class T>
T max5(const T[5]);
 
int main()
{
	int arri[5]={34,63,727,26,27};
	double arrd[5]={34,63,727,26,27};
	int maxi;
	double maxd;
	maxi=max5(arri);
	maxd=max5(arrd);
	cout<<"Max int: "<<maxi<<endl;
	cout<<"Max double: "<<maxd<<endl;
	
}
template <class T>
T max5(const T ar[5])
{
    T temp= ar[0];
    for(int i=1;i<5;i++)
    {
        if(ar[i]>temp)
        temp=ar[i];
    }
    return temp;
}