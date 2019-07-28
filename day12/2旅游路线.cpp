/*题目描述
这个暑假红红想去福建旅游,他决定走花费最小的路线.红红已经研究过了把自己从西安运送到福建的路线.
这些路线包括起始点和终点先一共经过T(1<=T<=2500)个城镇,方便地标号为1到T.
除了起点和终点外地每个城镇由两条双向道路连向至少两个其它地城镇.
每条道路有一个通过费用（包括油费,过路费等等）。 
给定一个地图,包含m(1<=m<=6200)条直接连接2个城镇的道路。每条道路由道路的起点Rs,终点Re(1<=Rs<=T;1<=Re<=T),
和花费(1<=Ci<=1000)组成.求从起始的城镇Ts(1<=Ts<=T)到终点的城镇Te(1<=Te<=T)最小的总费用. 
输入
第一行: 4个由空格隔开的整数: T m Ts Te 
第2到第C+1行: 第i+1行描述第i条道路.有3个由空格隔开的整数: Rs Re和Ci 
输出
一个单独的整数表示从Ts到Te的最小总费用.数据保证至少存在一条道路. 
样例输入
7 11 5 4 
2 4 2 
1 4 3 
7 2 2 
3 4 3 
5 7 5 
7 3 3 
6 1 1 
6 3 4 
2 4 3 
5 6 3 
7 2 1 
样例输出
7
提示
5->6->1->4(3+1+3)
*/

/*很裸的任意两点最短路，SPFA一下就好了，当然还有很多办法。*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int T, C, Te, Ts, head[63000], tot, dist[63000];
bool passby[63000];
queue<int> q;

struct Edge
{
    int to, dist, next;
}edge[63000];

void add(int ff,int tt,int dd)
{
    edge[++tot].to = tt;
    edge[tot].dist = dd;
    edge[tot].next = head[ff];
    head[ff] = tot;
}

void spfa(int s)
{
    dist[s] = 0;
    passby[s] = 1;
    q.push(s);
    for(; !q.empty(); ) {
        int x = q.front(); 
		q.pop(); 
		passby[x] = 0;
        for(int i = head[x]; i; i = edge[i].next) {
            Edge e = edge[i];
            if(dist[e.to] > dist[x] + e.dist) {
                dist[e.to] = dist[x] + e.dist;
                if(!passby[e.to]) {
                    passby[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
    }
}
int main() {
    cin >> T >> C >> Ts >> Te;
    for(int i = 1; i <= T; i++)	dist[i] = 0x7fffffff;
    for(int i = 1; i <= C; i++) {
        int Rs, Re, Ci;
        cin >> Rs >> Re >> Ci;
        add(Rs, Re, Ci);
		add(Re, Rs, Ci);
    }
    spfa(Ts);
    cout << dist[Te];
    return 0;
}


