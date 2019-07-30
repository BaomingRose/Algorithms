#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 200001;
int isprime[MAXN];
int vis[MAXN]; 

void eulerSieve(int a, int b, int* count, int* an) {
	*count = 0;
	*an = 0;
	memset(vis, 0, sizeof(vis));
	for(int i = 2; i <= b; ++i) {
		if(!vis[i]) {
			isprime[(*count)++] = i;
			if(i >= a)
				(*an)++;
		}
		for(int j = 0; j < *count && i * isprime[j] <= b; ++j) {
			vis[i * isprime[j]] = 1;
			if(i % isprime[j] == 0)
				break;
		}
	}
}


int main() {
	int num;
	int a, b;
	int an = 0;
	int count = 0;
	cin >> num; 
    while(num--) {
    	cin >> a >> b;
    	eulerSieve(a, b, &count, &an);
    	cout << an << endl;
    }
    return 0;
}
