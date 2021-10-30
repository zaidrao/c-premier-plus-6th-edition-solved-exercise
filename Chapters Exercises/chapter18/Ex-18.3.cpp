#include <iostream>

long double tot = 0;
void sum_values(){}
template <typename T,typename... Args>
long double sum_values(T value, Args... args)
{
	tot += value;
	sum_values(args...);
	return tot;
}

int main()
{
	using namespace std;
	auto ld = sum_values(6,1,7.7,8,9.999,'h');
	cout<<ld;
}