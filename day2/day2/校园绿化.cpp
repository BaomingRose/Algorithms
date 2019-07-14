/*
学校决定要在大小为N*M的空地里的多个区域种树(空地的左上角坐标为(1，1)，表示第1行第1列的空间)。
并且给出多个需要种树的区域(该区域保证完全在上述空地内，不存在有超出给定空地的部分)。
每次给定两个坐标(X1，Y1)、(X2，Y2)，表示左上角为(X1，Y1)，右下角为(X2，Y2)的需要种树的区域(包含端点的边界)。
对于每一个面积为1的空间，如果已经有了树，则不需要重复种树，如果没有树，则需要种上一棵树。
坐标(x，y)表示第x行第y列的空间。*/

#if 0

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int map[1005][1005];
int main(int argc, char const *argv[])
{
	int n, m, k;

	while (~scanf("%d %d %d", &n, &m, &k))
	{
		if (!n && !m && !k) break;
		memset(map, 0, sizeof(map));
		int a, b, c, d;
		for (int i = 0; i < k; ++i)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			for (int j = a; j <= c; ++j)
			{
				for (int s = b; s <= d; ++s)
				{
					map[j][s] = 1;
				}
			}
		}
		int sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (map[i][j]) sum++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}

#endif
