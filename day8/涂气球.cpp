/*小学生红红有N个气球排成一排，从左到右依次编号为123....N.
每次给定2个整数a b(a <= b)调皮的红红想拥有很多种不同颜色的气球，
于是他从气球a开始到气球b依次给每个气球涂一次颜色。
但是N次以后红红已经忘记了第I个气球已经涂过几次颜色了，
你能帮他算出每个气球被涂过几次颜色吗？*/

#include<iostream>
using namespace std;
#include<cstring> 

const int maxn = 100005;
int ax[maxn];

void change(int a, int b) {
	for(int i = a; i <= b; ++i) {
		++ax[i];
	}
}

int main() {
	int num;
	int a, b;
	int tmp;
	while(cin >> num && num) {
		memset(ax, 0, sizeof(ax));
		tmp = num;
		while(num--) {
			cin >> a >> b;
			change(a, b);
		}
		for(int i = 1; i <= tmp; ++i) {
			if(i == 1)
				cout << ax[i];
			else
				cout << " " << ax[i];
		}
		cout << endl;
	}
	return 0;
}

/*测试样例 
3
1 1
2 2
3 3
3
1 1
1 2
1 3
0*/
