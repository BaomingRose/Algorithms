/*红红准备了m斤肉肉准备和肉店兑换金钱以供自己上网码代码，
现在有n家肉店，第i家肉店最多需要J[i]斤肉肉，
如果全部交换红红可以获得F[i]美金，当然红红可以选择在某家肉店只交换一部分，
红红问你他最多能获得多少美金。*/

#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 5;
struct node {
	int j, f;
	double d;
	friend bool operator < (node a, node b) {
		return a.d > b.d;
	}
} dp[maxn];

int main() {
	int m, n;
	cin >> m >> n;
	for(int i = 0; i < n; ++i) {
		cin >> dp[i].f >> dp[i].j;
		dp[i].d = dp[i].f * 1.0 / dp[i].j;
	}
	sort(dp, dp + n);
	double ans = 0;
	for(int i = 0; i < n; ++i) {
		if(m >= dp[i].j) {
			m -= dp[i].j;
			ans += dp[i].f;
		}else {
			ans += m * dp[i].d;
			break;
		}
	}
	printf("%.3f", ans);
	return 0;
}

