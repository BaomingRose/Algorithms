/*差分约束模板题*/
/*题目描述:
当排队等候喂食时,奶牛喜欢和它们的朋友靠近些.FJ 有N头奶牛,编号从1到N,沿一条直线站着等候喂食.
奶牛排在队伍中的顺序和它们的编号是相同的.因为奶牛相当苗条,所以可能有两头或者更多奶牛站在同一位置上.
如果我们想象奶牛是站在一条数轴上的话,允许有两头或更多奶牛拥有相同的横坐标.一些奶牛相互间存有好感,
它们希望两者之间的距离不超过一个给定的数L.另一方面,一些奶牛相互间非常反感,它们希望两者间的距离不小于一个给定的数D.
给出ML条关于两头奶牛间有好感的描述,再给出MD条关于两头奶牛间存有反感的描述.
你的工作是:如果不存在满足要求的方案,输出-1;如果1号奶?和N号奶牛间的距离可以任意大,输出-2;
否则,计算出在满足所有要求的情况下,1号奶?和N号奶牛间可能的最大距离.
输入描述:
第一行读人三个整数N,ML,MD.
接下去ML行每行有三个正整数A,B,D(1<=A<B<=N),表示奶牛A和奶牛B至多相隔D的距离.
接下去MD行每行有三个正整数A,B,D(1<=A<B<=N),表示奶牛A和奶牛B至少相隔D的距离.
输出描述:
如果不存在满足要求的方案,输出-1;如果1号奶?和N号奶牛间的距离可以任意大,输出-2;
否则,计算出在满足所有要求的情况下,1号奶?和N号奶牛间可能的最大距离.
样例输入:
4 2 1
1 3 10
2 4 20
2 3 3
样例输出:
27
样例说明:
四只牛分别在0,7,10,27
*/ 

/*
差分约束，由于题目求最大值，所以最短路，把约束条件化成x-y<=b的形式
对于距离条件：d[i+1]>=d[i]        =>       d[i]-d[i+1]<=0      =>     连一条从i+1到i，权值为0的边
对于喜欢条件：d[x]-d[y]<=L(x>y)   =>       连一条从y到x，权值为L的边
对于讨厌条件：d[x]-d[y]>=L(x>y)   =>       d[y]-d[x]<=-L       =>     连一条从x到y，权值为-L的边
存在负环，输出-1，从1号点走不到n号点，输出-2
把一号奶牛看成在原点，答案为d[n]*/ 

//差分约束+spfa
/*这道题是一个差分约束的题目，根据牛之间的关系就可以确定牛与牛之间的约束方程，
根据约束方程建图跑最短路就可以了。
需要注意的是牛的位置坐标必须按他的序号依次排列所以每次建边的时候要注意牛的编号的大小再确定方向。*/

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
 
