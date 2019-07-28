/*��Ŀ����
����һ��ͼ�����ҵ����е����·������������˳���������
����
 n ���� m ���� (1��n  m �� 100)
�� u �� v �ı�ȨΪ w �����ߣ�
���
�밴������˳��������·����ı�
Ҫ��û�����·���-1
��������
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
�������
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
