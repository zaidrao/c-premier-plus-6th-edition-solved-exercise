#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef  vector<int> vint;

int randomfunc(int j)
{
	return rand() % j;
}

vint Lotto(int range, int num)
{
	vint random;
	for(int i=0;i<range ;i++)
	{
		random.push_back(i);
	}
	random_shuffle(random.begin(),random.end(), randomfunc);
	vint selected;
	copy(random.begin(),random.begin()+num,insert_iterator<vint>(selected,selected.begin()));
	sort(selected.begin(),selected.end());
	return selected;
}

int main()
{
	srand(time(0));
	vint winner = Lotto(50,5);
	ostream_iterator<int, char> out(cout," ");
	copy(winner.begin(),winner.end(),out);
}