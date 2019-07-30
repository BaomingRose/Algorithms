#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 200001;
int isprime[MAXN];
int vis[MAXN]; 

void eulerSieve(int n, int* count) {
	*count = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 2; i <= n; ++i) {
		if(!vis[i])
			isprime[(*count)++] = i;
		for(int j = 0; j < *count && i * isprime[j] <= n; ++j) {
			vis[i * isprime[j]] = 1;
			if(i % isprime[j] == 0)
				break;
		}
	}
}

void isPrime(int n, int count) {
	if(isprime[count - 1] == n)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

int main() {
	int n;
	int count = 0;
    while(cin >> n && n) {
    	eulerSieve(n, &count);
        isPrime(n, count);
    }
    return 0;
}
