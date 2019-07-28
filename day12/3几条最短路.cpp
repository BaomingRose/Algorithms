/*��Ŀ����
����һ��n������m���ߵ�������Ȩͼ��������Ϊ1~n�� �ʴӶ��� 1 ��ʼ��������ÿ��������·�м�����
����
��һ�а�������������n��mΪͼ�Ķ������������
������m�У�ÿ������������x��y�� ��ʾ��һ������ x ���򶥵� y �ıߣ���ע��������Ի����رߡ�
���
���У�ÿ��һ���Ǹ��������� i ������Ӷ��� 1 ������ i��������ͬ�����·�����ڴ��п��ܻ�ܴ�
��ֻ��Ҫ��� ans mod 100003 ��Ľ�����ɡ�����޷��ﵽ���� i �����0
��������
5 7
1 2
1 3
2 4
3 4
2 3
4 5
4 5
�������
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
