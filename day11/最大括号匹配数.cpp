/*题目描述
已知有两种括号匹配类型，分别是‘(’和‘)’，‘[’和‘]’。
给定一个字符串，只包含这 4 种符号，长度不超过100。
求出可以匹配括号的最大数量。
输入
输入有多组测试数据，输入0时结束。
每组测试样例只有一行，只包含 ' ( ' ，' ) '，  ' [ '，  ' ] ' 四种符号，且长度不超过一百
输出
每组测试样例输出一行，结果为可以匹配括号的最大数目。
样例输入
((()))
()()()
()))()
([()])
0
样例输出
6
6
4
6
*/

#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 105;
int dp[maxn][maxn];
string V;
int main() {
    while (cin >> V, V[0] != '0') {
        int n = V.size();
        for (int i = 0; i <= n; i++) {
            memset(dp[i], 0, sizeof(dp[i]));
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (V[i] == '(' && V[j] == ')' || 
                V[i] == '[' && V[j] == ']') {
                    if (i + 1 > j - 1)
                        dp[i][j] = 2;
                    else
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                for (int k = i; k < j; k++) {
                    dp[i][j] = max(dp[i][j], 
                    dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        cout << dp[0][n - 1] << endl;
        V.clear();
    }
    return 0;
}
