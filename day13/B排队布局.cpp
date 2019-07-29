/*���Լ��ģ����*/
/*��Ŀ����:
���ŶӵȺ�ιʳʱ,��ţϲ�������ǵ����ѿ���Щ.FJ ��Nͷ��ţ,��Ŵ�1��N,��һ��ֱ��վ�ŵȺ�ιʳ.
��ţ���ڶ����е�˳������ǵı������ͬ��.��Ϊ��ţ�൱����,���Կ�������ͷ���߸�����ţվ��ͬһλ����.
�������������ţ��վ��һ�������ϵĻ�,��������ͷ�������ţӵ����ͬ�ĺ�����.һЩ��ţ�໥����кø�,
����ϣ������֮��ľ��벻����һ����������L.��һ����,һЩ��ţ�໥��ǳ�����,����ϣ�����߼�ľ��벻С��һ����������D.
����ML��������ͷ��ţ���кøе�����,�ٸ���MD��������ͷ��ţ����з��е�����.
��Ĺ�����:�������������Ҫ��ķ���,���-1;���1����?��N����ţ��ľ�����������,���-2;
����,���������������Ҫ��������,1����?��N����ţ����ܵ�������.
��������:
��һ�ж�����������N,ML,MD.
����ȥML��ÿ��������������A,B,D(1<=A<B<=N),��ʾ��ţA����ţB�������D�ľ���.
����ȥMD��ÿ��������������A,B,D(1<=A<B<=N),��ʾ��ţA����ţB�������D�ľ���.
�������:
�������������Ҫ��ķ���,���-1;���1����?��N����ţ��ľ�����������,���-2;
����,���������������Ҫ��������,1����?��N����ţ����ܵ�������.
��������:
4 2 1
1 3 10
2 4 20
2 3 3
�������:
27
����˵��:
��ֻţ�ֱ���0,7,10,27
*/ 

/*
���Լ����������Ŀ�����ֵ���������·����Լ����������x-y<=b����ʽ
���ھ���������d[i+1]>=d[i]        =>       d[i]-d[i+1]<=0      =>     ��һ����i+1��i��ȨֵΪ0�ı�
����ϲ��������d[x]-d[y]<=L(x>y)   =>       ��һ����y��x��ȨֵΪL�ı�
��������������d[x]-d[y]>=L(x>y)   =>       d[y]-d[x]<=-L       =>     ��һ����x��y��ȨֵΪ-L�ı�
���ڸ��������-1����1�ŵ��߲���n�ŵ㣬���-2
��һ����ţ������ԭ�㣬��Ϊd[n]*/ 

//���Լ��+spfa
/*�������һ�����Լ������Ŀ������ţ֮��Ĺ�ϵ�Ϳ���ȷ��ţ��ţ֮���Լ�����̣�
����Լ�����̽�ͼ�����·�Ϳ����ˡ�
��Ҫע�����ţ��λ��������밴�������������������ÿ�ν��ߵ�ʱ��Ҫע��ţ�ı�ŵĴ�С��ȷ������*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 1005;
const int inf = 0x3f3f3f3f;
int vis[maxn];
int dis[maxn];
int visitcnt[maxn];
struct node {
    int u, v, w, next;
};
int head[maxn];
node e[maxn*maxn];

void init() {
    memset(visitcnt, 0, sizeof(visitcnt));
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
    memset(dis, inf, sizeof(dis));
}
int spfa(int n, int b) {
    queue<int> q;
    dis[b] = 0;
    vis[b] = 1;
    q.push(b);
    while(!q.empty()) {
        int now = q.front();
        visitcnt[now]++;
        if(visitcnt[now] > n) {
            return -1;
        }
        q.pop();
        vis[now] = 0;
        for(int i = head[now]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if(dis[v] > dis[now] + e[i].w) {
                dis[v] = dis[now] + e[i].w;
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return dis[n];
}
int main() {
    int n, ml, md, cnt;
    while(~scanf("%d %d %d", &n, &ml, &md)) {
        int a, b, c;
        init();
        cnt = 0;
        for(int i = 0; i < ml; i++) {
            scanf("%d%d%d", &a, &b, &c);
            int v = max(a, b);
            int u = min(a, b);
            e[++cnt].u = u;
			e[cnt].v = v;
            e[cnt].w = c;
			e[cnt].next = head[a];
            head[a] = cnt;
        }
        for(int i = 0; i < md; i++) {
            scanf("%d%d%d", &a, &b, &c);
            int u = max(a, b);
            int v = min(a, b);
            e[++cnt].u = u;
			e[cnt].v = v;
            e[cnt].w = -c;
			e[cnt].next = head[b];
            head[b] = cnt;
        }
        int ans = spfa(n,1);
        if(ans == -1)
			printf("-1\n");
        else if(ans == inf)
			printf("-2\n");
        else 
			printf("%d\n", ans);
    }
    return 0;
}
 
