/*
���㼧��Ϊ����������Ĵ��ڣ�����С��Χ�Ƶ�������������Ҫ�Լ������κ����ݡ�
������ͻȻ��Ѫ����������һ��ѭ���ļ��㣬����̫�ò����Ե��������Լ��Եײ�������˽��ú�ǳ��
�������������㣬ϣ�����ܱ�дһ��������ģ��ѭ������Ľ����
����ҹ���ˣ����㼧��ʾ������������������̫������֣���������������һǧ����������Ͱչ�������һǧ�򣩣�����
�����չ���ʱ������"Go Out!!!".
������Ҫ��ȥ��дһ���������������
1. forѭ���Ŀ�ͷ f �����һ������n����ʾѭ��������0 < n <= 100��
	2.forѭ����ֹ���e����ʾѭ����ֹ��ÿһ��f ��Ӧһ�� n
	3. ����ָ� + ������ʹ���1��ʼ x Ϊ0*/

#if 0

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
#include <stack>
#include <string>
using namespace std;
typedef long long ll;
string a[120000];
int num[120000];
stack<ll> s;
int main()
{
	// map <string, int> mp;
	//
	// mp["+"] = 0;
	// mp["f"] = 1;
	// mp["e"] = 2;
	int n;
	ll k = 1LL * 10000000;

	scanf("%d", &n);
	memset(num, 0, sizeof num);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (a[i][0] == 'f') cin >> num[i];
		// cout << a[i] << " " << num[i] << endl;
	}
	ll x = 0;
	ll tem = 1;
	// bool flag = false;
	bool flag_x = false;
	// cout << n << endl;
	for (int i = 0; i < n; ++i)
	{
		if (a[i][0] == '+')
		{
			if (s.empty()) x += 1;
			else x += s.top();
		}
		// cout << n << endl;
		if (a[i][0] == 'f')
		{
			if (s.empty()) tem = 1;
			else tem = s.top();
			tem *= num[i];
			if (tem > k) s.push(k + 1);
			else s.push(tem);
		}
		// cout << n << endl;
		if (a[i][0] == 'e')
		{
			s.pop();
		}
		if (x > k)
		{
			flag_x = true;
			break;
		}
		// printf("%I64d %I64d %d\n", x, tem, top);
	}
	// std::cout << "1" << '\n';
	if (flag_x) printf("Go Out!!!\n");
	else printf("%lld\n", 1LL * x);
	return 0;
}
#endif
