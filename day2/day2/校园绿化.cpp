/*
ѧУ����Ҫ�ڴ�СΪN*M�Ŀյ���Ķ����������(�յص����Ͻ�����Ϊ(1��1)����ʾ��1�е�1�еĿռ�)��
���Ҹ��������Ҫ����������(������֤��ȫ�������յ��ڣ��������г��������յصĲ���)��
ÿ�θ�����������(X1��Y1)��(X2��Y2)����ʾ���Ͻ�Ϊ(X1��Y1)�����½�Ϊ(X2��Y2)����Ҫ����������(�����˵�ı߽�)��
����ÿһ�����Ϊ1�Ŀռ䣬����Ѿ�������������Ҫ�ظ����������û����������Ҫ����һ������
����(x��y)��ʾ��x�е�y�еĿռ䡣*/

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
