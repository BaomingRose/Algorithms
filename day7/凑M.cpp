/*��һ������ΪN�����飬��������Ǵ�������ѡȡԪ�����ճ���СΪM�����֣�
������û���ظ���Ԫ�أ�ÿ��Ԫ��ֻ����һ�Ρ�*/

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

