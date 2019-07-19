/*有一个长度为N的数组，你的任务是从数组中选取元素来凑出大小为M的数字，
数组中没有重复的元素，每个元素只能用一次。*/

#include<iostream>
using namespace std;
#include<algorithm>

const int maxn = 10000 + 8;
int a[maxn];
int n, m;

int main()
{
	while(cin >> n >> m)
	{
		for(int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		for(int i = n - 1; i >= 0 && m; i--)
		if(m >= a[i])
		m -= a[i];
		if(!m) printf("YES\n");
		else printf("NO\n"); 
	}
}

