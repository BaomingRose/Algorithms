/*题目描述
红红的面前有n个方格，每个方格上面写了一个数字。
红红突然想起了儿时的“跳房子”游戏。于是决定树立一个新的规则。
红红可以从方格外开始起跳。他每跳到一个格子上，就可以获得格子上数字那么多钱！
但是他下一步跳到的格子上的数字必须比当前格子上的数字更大。
红红慌了，不知道他能拿到的钱是多少。聪明的你可以帮他计算一下吗？
输入
输入包含多组测试样例。每一个测试样例被如下描述：
N v1 v2 ... vN
保证对于每一个测试样例，N ≤ 1000，并且 vi 在32位整数范围内。
以0开头的测试样例作为输入终止标志，并且这组样例不被处理
输出
对于每一个测试样例，输出根据规则他最多可以获得的金额，每个测试样例一行。
样例输入
3 1 3 2
5 1 1 2 3 4
4 3 2 1 1
0
样例输出
4
10
3
*/

#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1005;
int dp[maxn];
int num[maxn];


//总结一下这类的线性DP。
//这里dp数组保存的是每一个点为止这个位置上的递增子序列之和
//然后这个地方的每一个确定的值再与之前的去比较，最后加上相应的值即可。

int main() {
    //freopen("test1.in", "r", stdin); 
    //freopen("test1.out", "w", stdout); 
    int T;
    while (cin >> T && T) {
        for (int i = 1; i <= T; i++) {
            cin >> num[i];
        }
        memset(dp, 0, sizeof dp);
        dp[1] = num[1];
        for (int i = 2; i <= T; i++) {
            dp[i] = num[i];
            for (int j = i - 1; j >= 1; j--) {
                if (num[i] > num[j]) {
                    dp[i] = max(dp[i], dp[j] + num[i]);
                }
            }
        }
        int Max = 0;
        for (int i = 1; i <= T; i++) {
            Max = max(Max, dp[i]);
        }
        cout << Max << endl;
    }
    return 0;
}
