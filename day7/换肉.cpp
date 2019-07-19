/*���׼����m������׼�������һ���Ǯ�Թ��Լ���������룬
������n����꣬��i����������ҪJ[i]�����⣬
���ȫ�����������Ի��F[i]���𣬵�Ȼ������ѡ����ĳ�����ֻ����һ���֣�
�������������ܻ�ö�������*/

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

