#include<iostream>
#include<cstdio>
using namespace std;

const int mod = 1000000009;

//¿ìËÙÃÝËã·¨ 
long long poww(long long a, long long n, int mod) {
	long ret = 1;
	while(n) {
		if(n & 1)
			ret = (ret * a) % mod;
			a = (a * a) % mod;
			n >>= 1;
	}
	return ret;
}

long long int fun(long long int n) {
	return 4 * poww(3, n - 2, mod);
}

int main() {
	long long int n;
	//int flag = 0; 
	while(scanf("%lld", &n)) {
		/*if(flag == 0) {
			cout << fun(n);
			flag = 1;
		}*/
		cout << fun(n) << endl;
	}
}
