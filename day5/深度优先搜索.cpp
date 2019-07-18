#include<iostream>
using namespace std;
#include<cstring>
const int maxn = 100 + 8;
char oil[maxn][maxn];
int vis[maxn][maxn];
int cnt;
int n, m;

void dfs(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return ;
    if(oil[x][y] != '@' || vis[x][y]) return ;
    vis[x][y] = 1;
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; ++j)
        {
            if(i || j)
                dfs(x + i, y + j);
        }
    }
    
}

int main()
{
    while(cin >> n >> m && n && m)
    {
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> oil[i];
        }
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(oil[i][j] == '@' && !vis[i][j])
                {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
