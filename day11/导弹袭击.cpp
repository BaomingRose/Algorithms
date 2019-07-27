/*题目描述
某国为了防御敌国的导弹袭击发展出一种导弹拦截系统.但是这种导弹拦截系统有一个缺陷:
虽然它的第一发炮弹能够到达任意的高度但是以后每一发炮弹都不能超过前一发的高度.
某天雷达捕捉到敌国的导弹来袭.由于该系统还在试用阶段所以只有一套系统因此有可能不能拦截所有的导弹.
怎么办呢?多搞几套系统呗!你说说倒蛮容易成本呢?成本是个大问题啊.
所以俺就到这里来求救了请帮助计算一下最少需要多少套拦截系统.
输入
输入若干组数据.每组数据包括:导弹总个数(正整数)导弹依此飞来的高度
(雷达给出的高度数据是不大于30000的正整数用空格分隔)
输出
对应每组数据输出拦截所有导弹最少要配备多少套这种导弹拦截系统.
样例输入
8 389 207 155 300 299 170 158 65
样例输出
2
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    //freopen("test1.in", "r", stdin);   
    //freopen("test1.out", "w", stdout); 
    int T;
    while (~scanf("%d", &T)) {
        int dp[T + 5];
        int data[T + 5];
        data[0] = 0;
        int num = 0;
        for (int i = 1; i <= T; i++) {
            cin >> data[i];
            dp[i] = 1;
        }
        for (int i = 2; i <= T; i++) {
            for (int j = i - 1; j >= 1; j--) {
                if (data[i] > data[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                num = max(num, dp[i]);
            }
        }
        cout << num << endl;
    }
    return 0;
}
