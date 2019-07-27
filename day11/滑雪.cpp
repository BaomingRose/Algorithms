/*题目描述
Michael喜欢滑雪这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，
而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。Michael想知道在一个区域中最长底滑坡。
区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子 
1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，
一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。
输入
输入的第一行表示区域的行数R和列数C(1 <= RC <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。
输出
输出最长区域的长度。
样例输入
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
样例输出
25
*/

#include <iostream>
#include <cstdlib>
#include <cstring> 
#define INF 0x3f3f3f3f
#define N 110
using namespace std;
int dis[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int len[N][N], a[N][N];
int m, n;
int dp(int x, int y) {
    int tx, ty, k, s, ms;
    ms = 0;
    if (len[x][y] != 0) //递归出口；
        return len[x][y];
    for (k = 0; k <= 3; k++) {
        tx = dis[k][0] + x;
        ty = dis[k][1] + y;
        if (tx < 0 || ty < 0 || tx > m - 1 || ty > n - 1)
            continue;
        if (a[tx][ty] < a[x][y]) {
            s = dp(tx, ty);
            ms = max(ms, s);
        }
    }
    len[x][y] = ms + 1;
    return len[x][y];
}
int main() {
    //freopen("test1.in", "r", stdin); 
    //freopen("test1.out", "w", stdout); 
    int i, j, Max;
    while (~scanf("%d%d", &m, &n)) {
        memset(a, 0, sizeof(a));
        memset(len, 0, sizeof(len));
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        Max = -1;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                Max = max(Max, dp(i, j));
        printf("%d\n", Max);
    }
    return 0;

}
