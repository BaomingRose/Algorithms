/*题目描述
老左今天打算去小寨逛街,他决定要找到最短的一条路,时间才是最重要的,于是他想知道最少要多少时间才能到小寨
假设一共有n 个车站，我们学校门口的车站编号为1， 小寨站编号为n，之后会给出一个m，
随后会给出m条双向通道以及通过所需要的时间。
输入
第一行N ， M （ 2 <= N <= 1000 1 <= M <= 2000)
第二行到第M+ 1行，三个数字a ， b ， c 表示a 站点到b 站点有一条路，需要 c min 
输出
一行表示他需要的最少时间
样例输入
5 5
1 2 20
2 3 30
3 4 20
4 5 20
1 5 100
样例输出
90
*/

#include<iostream>
using namespace std;
#include<cstring>

#define maxn 1005
#define INF 0x3f3f3f3f
int map[maxn][maxn];
int dis[maxn], check[maxn];

int dijkstra(int n) {		//求顶点1到顶点n的最短路径 
	memset(check, 0, sizeof(check));
	memset(dis, 0, sizeof(dis));
	for(int i = 1; i <= n; ++i) {
		dis[i] = map[1][i];			//初始化dis从源点即1到n的长度 
	}
	check[1] = 1, dis[1] = 0;
	int minx = 0, pos;
	//开始主循环，每次求得v1到某个顶点的最短路径 
	for(int i = 1; i <= n; ++i) {
		minx = INF;
		for(int j = 1; j <= n; ++j) {
			if(!check[j] && minx > dis[j]) {	//j顶点离v1更近 
				minx = dis[j];
				pos = j;
			}
		}
		check[pos] = 1;
		for(int j = 1; j <= n; ++j) {		//更新当前最短路径及距离 
			if(!check[j] && dis[j] > minx + map[pos][j]) {		//修改dis[j] 
				dis[j] = minx + map[pos][j];
			}
		}
	}
	return dis[n];
}

int main() {
	memset(map, INF, sizeof(map));		//强调重要的：现将所有权值赋无穷大 
	int N, M;
	cin >> N >> M;
	int a, b, c;
	for(int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		map[a][b] = map[b][a] = c;
	}
	cout << dijkstra(N) << endl;
	return 0;
}
