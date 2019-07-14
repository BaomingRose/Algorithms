#if 0
#include<iostream>
using namespace std;

int Fab(int n)
{
	if (n <= 2) {
		return 1;
	}
	int last2 = 1;
	int last1 = 1;
	int cur = 0;
	for (int i = 3; i <= n; ++i) {
		cur = last1 + last2;
		last2 = last1;
		last1 = cur;
	}
	return cur;
}

int main()
{
	long long int a;
	int c = 1;
	do
	{
		a = Fab(c);
		++c;
	} while (a > 0);
	cout << Fab(c - 2);
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <string.h>
int main()
{
	long long f[1000];

	f[1] = f[2] = 1;
	for (int i = 3; i < 1000; ++i) {
		f[i] = f[i - 1] + f[i - 2];
		if (f[i] < 0) {
			printf("%lld\n", f[i - 1]);
			break;
		}
	}
	return 0;
}
#endif
