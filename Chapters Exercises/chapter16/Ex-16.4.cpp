#include <iostream>
#include <set>

using namespace std;

void show (long n)
{
	cout<<n<<" ";
}
int reduce(long ar[], int n)
{
	// use set to store array elements it store elements as a key so it store unique elements only. set also sort the array
	set<long> sorted;
	for(int i =0; i < n;i++)
	{
		sorted.insert(ar[i]);
	}
	cout<<"Sorted: ";
	for_each(sorted.begin(),sorted.end(),show);
	return sorted.size();
}

int main()
{
	long ar[]={45,6,76,76,57,45};
	int s=reduce(ar,6);
	cout<<"\nReduce array size: "<< s;
}