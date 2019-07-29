/*��Ŀ����
����n��������m������ʽ,ÿ������ʽ���� x[i]-x[j]<=a[k](0<=i j<n 0<=k<m,a[k]��֪),�� x[n-1]-x[0]�����ֵ.
����
��һ�� n m��ʾ����n�������� m������ʽ
�������� m�л�����������abc��ʾXa-Xb<=c;
���
���һ�н����ʾ Xn-1-X0�����ֵ.
��������
4 5
1 0 2
2 0 7
3 0 8
2 1 3
3 2 2
�������
7
*/

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 1005;
const int inf = 0x3f3f3f3f;
int dis[maxn];
int vis[maxn];
int head[maxn];
struct edge {
    int to, w, next;
};
edge e[maxn];

void init() {
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
    memset(dis, inf, sizeof(dis));
}
int spfa(int b,  int n) {
    queue<int> q;
    vis[b] = 1;
    dis[b] = 0;
    q.push(b);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        vis[now] = 0;
        for(int i = head[now]; i != -1; i = e[i].next) {
            int v = e[i].to;
            if(dis[v] > dis[now] + e[i].w) {
                dis[v] = dis[now] + e[i].w;
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return dis[n-1];
}
int main() {
    int n, m;
    int cnt = 0;
    scanf("%d%d", &n, &m);
    init();
    for(int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[++cnt].to = a;
        e[cnt].w = c;
        e[cnt].next = head[b];
        head[b] = cnt;
    }
    cout << spfa(0, n) << endl;
    //for(int i = 0; i < n; i++)
    //cout << dis[i] << endl;
    return 0;
}


