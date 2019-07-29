/*有 n 个节点，编号为 1~n，有 m 条边，每条边都有一个距离。两点之间最多只有 1 条边。
现在你需要选取 n-1 条边，使得所有点都连接起来都有通路。n-1 条边距离之和越小分数越高。
万钧立马意识到这道题是求最小生成树的，并且每个人的答案不能相同，万钧根据瞪眼法立马瞪出了答案，
然而他还是等待雷婷先做完。现在雷婷已经找到了距离最短的1种方案，不过他俩太心有灵犀了，答案一模一样，
万钧想获得第 2 名，请你帮万钧想一种方案，距离之和越短越好，但不能和雷婷的结果相同。
一条边不同即可认为不同。如果找不到输出 -1。当然存在一种情况，如果雷婷的方案是没有方案求出最短距离，
即表示该图没有最小生成树，即输出 -1。总之雷婷的方案是最优解的一种。
输入
存在多组数据，第一行一个正整数 t，表示有 t 组数据。
每组数据第一行有两个整数 n 和 m（2 ≤ n ≤ 100，1 ≤ m ≤ 1000)，之后 m 行，
每行三个正整数 s，e，w，表示 s 到 e 的双向路的权值为 w。
输出
输出次小生成树的值（如果存在多个最小生成树或仅有一个树，则次小生成树就是最小生成树，输出-1），如果不存在输出 -1。
样例输入
1
3 3
3 1 3
1 2 1
2 3 2
样例输出
4
*/
/*这是一道次小生成树的题目，在最小生成树的基础上加一些操作就好了。
注意次小生成树不存在的情况主是，可能这个图连最小生成树都没有，还有一种可能就是有两棵权值一样的最小生成树。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn=0x3f3f3f3f;
int map[105][105];
int vis[105];
int dis[105];
int per[105];
int mapvis[105][105];
int max_ab[105][105];
int ans,ans1;

void init() {
    for(int i = 0; i < 105; i++) {
        vis[i] = 0;
        for(int j = 0; j < 105; j++) {
            map[i][j] = maxn;
            mapvis[i][j] = 0;
        }
    }
    ans = 0;
	ans1 = maxn;
}
void prim(int n) {
    vis[1] = 1;
    for(int i = 1; i <= n; i++) {
        dis[i] = map[1][i];
        per[i] = 1;
    }
    for(int i = 1; i < n; i++) {
        int minn = maxn, g;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && minn > dis[j]) {
                minn = dis[j];
                g = j;
            }
        }
        ans += minn;
        vis[g] = 1;
        mapvis[g][per[g]] = mapvis[per[g]][g] = 1;
        for(int k = 1; k <= n; k++) {
            if(vis[k] && k != g) {
                max_ab[k][g] = max_ab[g][k] = max(max_ab[per[g]][k], dis[g]);
            }
            if(!vis[k]) {
                if(map[g][k] < dis[k]) {
                    dis[k] = map[g][k];
                    per[k] = g;
                }
            }
        }
    }
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(!mapvis[i][j] && map[i][j] != maxn) {
                ans1 = min(ans + map[i][j] - max_ab[i][j], ans1);
            }
        }
    }
}
int main() {
    int t, n, m;
    scanf("%d", &t);
    while(t--) {
        init();
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i++) {
            int xx, yy, vv;
            scanf("%d%d%d", &xx, &yy, &vv);
            map[xx][yy] = map[yy][xx] = vv;
        }
        prim(n);
        if(ans == ans1 || ans1 == maxn)
			printf("-1\n");
        else printf("%d\n", ans1);
    }
    return 0; 
}


