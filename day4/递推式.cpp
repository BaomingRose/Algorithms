#include<iostream>
using namespace std;

int Fun(int n, int a, int b)
{
	if(n == 1)
		return 1;
	return a * Fun(n - 1, a, b) + b;
}

int main()
{
	int a, b, n;
	while(cin >> a >> b >> n)
	{
		cout << Fun(n, a, b) << endl;
	}	
}
