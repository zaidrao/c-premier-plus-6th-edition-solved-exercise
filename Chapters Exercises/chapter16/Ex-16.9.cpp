#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef vector<int> vint;
typedef list<int> lint;

void arraySort(vint & v)
{
	clock_t start = clock();
	sort(v.begin(),v.end());
	clock_t stop = clock();
	cout<<"Array sorting time = "<<
	(double)(stop-start)/CLOCKS_PER_SEC<<endl;
}
void listSort(lint & l)
{
	clock_t start = clock();
	l.sort();
	clock_t stop = clock();
	cout<<"List sorting time = "<<
	(double)(stop-start)/CLOCKS_PER_SEC<<endl;
}
void psudoSort(lint &l, vint &v)
{
	clock_t start = clock();
	//copy to array
	copy(l.begin(),l.end(),
	insert_iterator<vint>(v,v.begin()));
	// sorting array
	sort(v.begin(),v.end());
	// copy to list
	copy(v.begin(),v.end(),
	insert_iterator<lint>(l,l.begin()));
	
	clock_t stop = clock();
	
	cout<<"List to array sorting time = "<<
	(double)(stop-start)/CLOCKS_PER_SEC<<endl;
}
void ranData(vint &v, int size)
{
	for(int i = 0; i<size; i++)
	{
		v.push_back((rand()%size));
	}
}
int main()
{
	srand(time(0));
	vint vi0;
	vint vi;
	lint li;
	// initialize array with data
	ranData(vi0,190000);
	// copy same data in vi and li
	copy(vi0.begin(),vi0.end(),
	insert_iterator<lint>(li,li.begin()));
	copy(vi0.begin(),vi0.end(),
	insert_iterator<vint>(vi,vi.begin()));
	cout.precision(3);
	// sorting array
	arraySort(vi);
	// sorting list
	listSort(li);
	// copy original data in list
	copy(vi0.begin(),vi0.end(),
	insert_iterator<lint>(li,li.begin()));
	// conversation sorting
	psudoSort(li,vi);
}