#include<iostream>
using namespace std;

long long int Factor(int n)
{
	if(n == 1)
		return 1;
	return n * Factor(n - 1);
}

int main()
{
	int n;
	while(cin >> n)
	{
		cout << Factor(n) << endl;
	}
	return 0;
}
