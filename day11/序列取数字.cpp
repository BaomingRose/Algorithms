/*题目描述
现在有一个序列，每次可以取最左端的数字或者最右端的数字。一共要分n次取完。
假设你第i次取的数字是x，你可以获得i*x的价值。你需要规划取数顺序，使获得的总价值之和最大。
输入
单组输入。
第一行一个数字n(1<=n<=2000)。
下面n行每行一个数字v(i)。(1<=v(i)<=1000)。
输出
输出一个数字，表示最大总价值和。
样例输入
5
1
3
1
5
2
样例输出
43
提示
按照这种下标顺序取数： 1 5 2 3 4
取出的数按顺序为：1 2 3 1 5
最大总价值和：1x1 + 2x2 + 3x3 + 4x1 + 5x5 = 43.
*/

/*
	这道题目就是典型的区间DP的题目了，对一个区间里面的值进行动态规划的求解，就像下面的状态转移方程
    dp[i][j] = max(dp[i + 1][j] + num[i] *(n + i - j),
    dp[i][j - 1] + num[j] * (n + i - j));

    这道题唯一特别难想到的是，这道题目是一道逆序求解的问题，
    意思就是从后面的状态往前面推，这当时的我就完全没有想到了。
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
const int maxn = 2005;
int dp[maxn][maxn];
int num[maxn];

int main() {
    //freopen("test3.in", "r", stdin);
    //freopen("test3.out", "w", stdout);
    while (~scanf("%d", &n)) {
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &num[i]);
            dp[i][i] = num[i];
        }
        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                //这里乘以 n + i - j 其实一开始的变形就是 n - (j - i + 1) + 1
                dp[i][j] = max(dp[i + 1][j] + num[i] * (n + i - j), dp[i][j - 1] + num[j] * (n + i - j));
            }
        }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}

