/*题目描述
有一天红红拿了奖学金，与此同时，红红说好了要请集训的所有同学去看电影，现在红红就要负责去购买电影票，
现在电影票可以一个一个的购买，也可以两个人一起购买，如果知道每个人单独买票花费的时间，
还有和前一个人一起买花费的时间，问最少花多长时间可以全部买完票。 
输入
给出 N(1<=N<=10)，表示有N组样例 
给出K (1<=K<=2000)，表示有K个人买票.. 
给出K个数表示这个人单独买票会花的时间..保证每个数 (0s<=Si<=35s) 
给出K-1个数，表示这个人和前面那个人一起买票会花的时间..保证每个数 (0s<=Si<=70s) 
输出
对于每一组数据，你需要给出电影院售票结束的时间，
售票开始的时间为 08:00:00 am. 时间格式为： HH:MM:SS am 或者 pm. 
具体看样例输出 
样例输入
2
2
20 25
40
1
8
样例输出
08:00:40 am
08:00:08 am
*/

/*
	这道题就是被前面的思想所影响，其实这道题不像前面前面几个状态一定会影响到后面的状态，
    仅仅只是一个一维的线性dp，考虑到前面的这些情况，他是另外的两个dp方程组进行放与不放的操作
    所以不会涉及到多个循环反复到前面之前的状态去寻找，
    只需要在一次遍历的过程中去实现究竟是一次还是两次的操作。

    跟着每一个状态往下面找出每一个位置的局部最优解 最后得到结果。
*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 2005;
int dp[maxn];
int s[maxn];
int d[maxn];

int main() {
    //freopen("test1.in", "r", stdin); 
    //freopen("test1.out", "w", stdout); 
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            dp[i] = s[i];
        }
        d[0] = 0;
        d[1] = 0;
        for (int i = 2; i <= n; i++) {
            cin >> d[i];
        }
        dp[0] = 0;
        dp[1] = s[1];
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + s[i], dp[i - 2] + d[i]);
        }
        int h = dp[n] / 3600 + 8;
        int m = dp[n] / 60 % 60;
        int s = dp[n] % 60;
        if (h <= 12)
        printf("%02d:%02d:%02d am\n", h, m, s);
        else
        printf("%02d:%02d:%02d pm\n", h, m, s);
    }
    return 0;
}
