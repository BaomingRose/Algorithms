/*欧洲冠军杯比赛日程安排
初赛阶段采用循环制， 共有n队参加，共进行n-1天，要求每队每天只能进行一场比赛，并且不能轮空
按照上述要求安排比赛日程，决定每天各队的对手
算法思想：根据分治算法思路，将所有参赛队伍分成两半，则n队的比赛日程表可以通过n/2个队的比赛日程来决定
然后按照上述一分为二的方法对参赛队进行划分，直到只剩余最后两队时为止*/ 

#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 64;
int a[MAXN + 1][MAXN + 1] = { 0 };

void gamecal(int k, int n) {		//处理编号k开始的n个球队的日程 
	int i, j;
	if(n == 2) {
		a[k][1] = k;	//参赛球队编号
		a[k][2] = k + 1;	//对阵球队编号 
		a[k + 1][1] = k + 1;	//参赛球队编号 
		a[k + 1][2] = k; 		//对阵球队编号 
	} else {
		gamecal(k, n / 2);
		gamecal(k + n / 2, n / 2);
		for(i = k; i < k + n / 2; ++i) {		//填充右下角 
			for(j = n / 2 + 1; j <= n; ++j) {
				a[i][j] = a[i + n / 2][j - n / 2];
			}
		}
		for(i = k + n / 2; i < k + n; ++i) {		//填充左下角 
			for(j = n / 2 + 1; j <= n; ++j) {
				a[i][j] = a[i - n / 2][j - n / 2];
			}
		}
	}
}

int main() {
	int m, i, j;
	cout << "参赛球队数：";
	cin >> m;
	j = 2;
	for(i = 2; i < 8; ++i) {
		j *= 2;
		if(j == m) break;
	}
	if(i >= 8) {
		cout << "参赛球队数必须为2的整数次幂，并且不超过64！" << endl;
		return 0;
	}
	gamecal(1, m);
	cout << endl << "编号 " ;
	for(i = 2; i <= m; ++i) {
		printf("%2d天 ", i - 1);
	}
	cout << endl;
	for(i = 1; i <= m; ++i) {
		for(j = 1; j <= m; ++j) {
			printf("%4d ", a[i][j]);
		}
		cout << endl;
	}
	return 0;
}

