/*题目描述
小红红非常喜欢数论，但是他对一些问题很不解。
例如有一次，他在幼儿园的操场上把 N 堆石子摆成了一排。(每堆石子都有一定的数量。)
小红红想，如果每次合并两堆石子的得分就等于这两堆石子的和。
把一排的 N 堆石子合并成一堆可以的得到的最高分是多少呢？
每次只能合并相邻的两堆，每次合并完成后，新的一堆石子和两边的石子又会形成新的相邻关系。
输入
输入包含多组测试数据。
对于每组测试数据：
第一行输入为 N ，表示一排上有 N 堆石子。(0 < N < 200)
第二行输入为 N 个正整数，代表第 i 堆石子的数量。（0 < ni < 100000）
输出
输出总得分的最大值。每个测试样例输出占一行。
样例输入
4
4 5 9 4
样例输出
54
*/

#include <iostream>
#include <cstdio>
using namespace std;
const int INF = -0x3f3f3f3f; //定义一个无穷大的值
const int maxn = 205;
int dp[maxn][maxn];
int sum[maxn][maxn], n, x;
int main() {
    sum[0][0] = 0; //初始化
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            sum[i][i] = x;
            fill(dp[i], dp[i] + maxn, INF); //初始化
            dp[i][i] = 0;
        }
        //区间dp
        for (int len = 2; len <= n; len++) { //枚举区间长度 
            for (int i = 1; (i + len - 1) <= n; i++) {//枚举区间起点
                int j = i + len - 1;
                for (int k = i; k < j; k++) {	//枚举中断点
                    sum[i][j] = sum[i][k] + sum[k + 1][j];
                    dp[i][j] = max(dp[i][j], dp[i][k] + 
                        dp[k + 1][j] + sum[i][j]);
                }
            }
        }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}
