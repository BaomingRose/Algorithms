/*题目描述
给出一个n个顶点m条边的无向无权图，顶点编号为1~n， 问从顶点 1 开始，到其他每个点的最短路有几条。
输入
第一行包含两个正整数n，m为图的顶点数与边数。
接下来m行，每行两个正整数x，y， 表示有一条顶点 x 连向顶点 y 的边，请注意可能有自环与重边。
输出
共行，每行一个非负整数，第 i 行输出从顶点 1 到顶点 i多少条不同的最短路，由于答案有可能会很大，
你只需要输出 ans mod 100003 后的结果即可。如果无法达到顶点 i 则输出0
样例输入
5 7
1 2
1 3
2 4
3 4
2 3
4 5
4 5
样例输出
1
1
1
2
4
*/

#include<cstdio>
using namespace std;

const int mod = 1e5+3;
const int maxn = 1e6+10;
const int maxm = 4e6+10;
int n, m;
int num[maxn];
int h[maxn], hs;
int et[maxm], en[maxm];

void add() {
    int a, b;
    scanf("%d%d", &a, &b);
    hs++, et[hs] = b, en[hs] = h[a], h[a] = hs;
    hs++, et[hs] = a, en[hs] = h[b], h[b] = hs;
}

int q[maxn], head, tail;
int d[maxn];

void bfs() {
    int a, b;
    q[tail++] = num[1] = d[1] = 1;
    while(head<tail) { 
        a = q[head++];
        b = d[a] + 1;
        for(int i = h[a]; i; i = en[i]) {
            if(!d[et[i]]) {
			d[et[i]] = b;
			q[tail++] = et[i];
			}
            if(b == d[et[i]]) {
			num[et[i]] += num[a];
			num[et[i]] %= mod;
			}
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++)
		add();
    bfs();
    for(int i = 1; i <= n; i++)
		printf("%d\n", num[i]);
    return 0;
}
