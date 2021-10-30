#include <iostream>
#include <set>

using namespace std;
template <class T>
void show (T n)
{
	cout<<n<<" ";
}

template <class T>
int reduce(T ar[], int n)
{
	// use set to store array elements it store elements as a key so it store unique elements only. set also sort the array
	set<T> sorted;
	for(int i =0; i < n;i++)
	{
		sorted.insert(ar[i]);
	}
	cout<<"Sorted: ";
	for_each(sorted.begin(),sorted.end(), show<T>);
	return sorted.size();
}

int main()
{
	string arr[]={"floor","floor","eat","this"};
	long ar[]={45,6,76,76,57,45};
	int s=reduce(arr,4);
	cout<<"\nReduce array size: "<< s;
}