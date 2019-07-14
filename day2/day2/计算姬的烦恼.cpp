/*
计算姬作为计算机届大姐大的存在，无数小弟围绕的她从来都不需要自己运算任何数据。
晚上她突然心血来潮，想试一试循环的计算，但是太久不动脑的她发现自己对底层运算的了解变得很浅。
所以她找来了你，希望你能编写一个程序，来模拟循环计算的结果。
但是夜深了，计算姬表示很困，所以她不想算太大的数字，于是她决定超过一千万的数字她就罢工（包括一千万）！！！
当她罢工的时候会输出"Go Out!!!".
现在需要你去编写一个程序，有三条命令：
1. for循环的开头 f ，后带一个数字n，表示循环次数（0 < n <= 100）
	2.for循环终止语句e，表示循环终止，每一个f 对应一个 n
	3. 自增指令， + ，遇到使其加1初始 x 为0*/

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
