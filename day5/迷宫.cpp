#include<iostream>
using namespace std;
#include<cstring>
#include<queue>
#include<stack>

const int maxn = 10 + 8;
int a[maxn][maxn];
int vis[maxn][maxn];
int step[maxn][maxn];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
struct node
{
	int x;
	int y;
	int cnt;
	node(int x = 0, int y = 0, int cnt = 0)
	{
		this->x = x;
		this->y = y;
		this->cnt = cnt;
	}
};

node fa[maxn][maxn];

int check(int x, int y)
{
	if(x < 0 || x > 4 || y < 0 || y > 5)
		return 0;
	if(a[x][y] == 1 || vis[x][y])
		return 0;
	return 1;
}

void bfs()
{
	memset(vis, 0, sizeof(vis));
	queue<node> q;
	node now;
	now.x = 0, now.y = 0, now.cnt = 0;
	q.push(now);
	step[now.x][now.y] = 0;
	while(!q.empty())
	{
		now = q.front();
		q.pop();
		vis[now.x][now.y] = 1;
		step[now.x][now.y] = now.cnt;
		if(now.x == 4 && now.y == 4)
			return ;
		for(int i = 0; i < 4; ++i)
		{
			node next;
			next.x = now.x + dx[i];
			next.y = now.y + dy[i];
			if(check(next.x, next.y))
			{
				next.cnt = now.cnt + 1;
				q.push(next);
				fa[next.x][next.y] = now;
			}
		}
	}
	return ;
}

void print_path(node u)
{
	stack<node> s;
	for(;;) 
	{
		s.push(u);
		if(step[u.x][u.y] == 0)
			break;
		u = fa[u.x][u.y];
	}
	while(!s.empty())
	{
		printf("(%d %d)\n", (s.top()).x, (s.top()).y);
		s.pop();
	}
	return ;
}

int main()
{
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	bfs();
	//printf("%d\n", step[4][4]);
	node ans(4, 4, step[4][4]);
	print_path(ans);
	
	return 0;
}
