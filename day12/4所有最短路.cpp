/*题目描述
给你一张图，请找到所有的最短路，并按照输入顺序输出出来
输入
 n 个点 m 条边 (1≤n  m ≤ 100)
从 u 到 v 的边权为 w （单边）
输出
请按照输入顺序输出最短路上面的边
要是没有最短路输出-1
样例输入
7 9
1 2 1
1 3 2
2 4 1
3 5 2
5 7 2
4 7 2
4 6 1
6 7 1 
1 7 4
样例输出
1 2 1
2 4 1
4 7 2
4 6 1
6 7 1
1 7 4
*/


#include<iostream>
#include<cstring> 
using namespace std;
#define maxn 10000

struct node {
	int u, v, w;
	int next;
} edge[maxn];

int head[maxn];
int cnt;

void add(int u, int v, int w) {
	edge[cnt].u = u;
	edge[cnt].v = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

int main() {
	memset(head, -1, sizeof(head));
	int n, t;
	cin >> n >> t;
	int u, v, w;
	cnt = 0;
	for (int i = 0; i < t; i++) {
		cin >> u >> v >> w;
		add(u, v, w);
	}
	cout << endl;
	cin >> u;
	for (int i = head[u]; ~i; i = edge[i].next) {
		cout << i << endl;
		cout << edge[i].u << " " << edge[i].v << " " << edge[i].w << endl;
	}
	return 0;
}
