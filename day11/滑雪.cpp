/*��Ŀ����
Michaelϲ����ѩ�Ⲣ����֣� ��Ϊ��ѩ��ȷ�ܴ̼�������Ϊ�˻���ٶȣ������������������б��
���ҵ��㻬���µף��㲻�ò��ٴ������»��ߵȴ������������㡣Michael��֪����һ����������׻��¡�
������һ����ά��������������ÿ�����ִ����ĸ߶ȡ�������һ������ 
1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
һ���˿��Դ�ĳ���㻬���������������ĸ���֮һ�����ҽ����߶ȼ�С��������������У�
һ���ɻ��еĻ���Ϊ24-17-16-1����Ȼ25-24-23-...-3-2-1��������ʵ�ϣ��������һ����
����
����ĵ�һ�б�ʾ���������R������C(1 <= RC <= 100)��������R�У�ÿ����C������������߶�h��0<=h<=10000��
���
��������ĳ��ȡ�
��������
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
�������
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
    if (len[x][y] != 0) //�ݹ���ڣ�
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
