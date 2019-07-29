/*题目描述
近日我们组织了一场奶牛的算法比赛,每头奶牛都有自己的代码风格,所以一个厉害的选手在自己的代码风格上就已经完全体现了出来,
现在我们给你一些关系表示两头牛之间谁更强一点,根据这些关系我们要确定所有的牛当中那些牛的位次是确定的.
并输出确定位次的奶牛数目.
输入
输入第一行两个数字nm分别表示 n 代表奶牛的数目,m代表的是关系的数目.
接下来的m行输入两个数字ab代表的是a比b要厉害所以他的排名也应该在b的前面.
输入范围 满足int数据类型
输出
输出一行代表可以确定位次的牛的数目.
样例输入
5 5
4 3
4 2
3 2
1 2
2 5
样例输出
2
*/

/*这道题目就是简单的闭包传递，根据初始矩阵求出他的传递闭包就可以了。
求出来之后我们可以根据每个点的出度和入度来判度这个点是否可以被准确定位。
只要自己可以击败的人数和可以击败自己的人数加起来为n-1，
就证明这个牛的位次是可以被确定的。*/


#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

int mp[105][105];
int in[105];
int out[105];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(mp, 0, sizeof(mp));
    for(int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        mp[a][b] = 1;
    }
    for(int i = 1; i <= n;i++) {
        for(int j = 1; j <= n; j++) {
            if(mp[j][i]) {
                for(int k = 1; k <= n; k++) {
                    mp[j][k] = mp[j][k] | mp[i][k];
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++){
            if(mp[i][j]) {
                out[i]++;
                in[j]++;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(in[i] + out[i] == n-1) {
            ans++;
        }
    }
    cout << ans << endl;
}


