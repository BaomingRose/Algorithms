/*
输入一个数（保证这个数的整数部分和小数部分都在int范围内）
请将小数部分转换成int形式并输出
*/

#if 0
#include<iostream>
using namespace std;
#include<string>

int main()
{
	string accept;
	int count = 0;	//接收字符的个数
	int i;		//记录小数点的下标
	int j;
	int ret = 0;
	while (1)
	{
		getline(cin, accept);
		count = accept.size();
		i = accept.find('.');
		for (j = i + 1; j < count; ++j)
		{
			ret = ret * 10 + (accept[j] - '0');
		}

		cout << ret << endl;
	}
	return 0;
}
#endif

#if 0
#include<stdio.h>

int main()
{
	int a, b;
	while (scanf("%d.%d", &a, &b) != EOF)
	{
		printf("%d\n", b);
	}
	return 0;
}
#endif


#if 0
#include <stdio.h>
#include <string.h>
int main()
{
	char a[100], b[100];
	int c = 0;

	while (~scanf("%s", a)) {
		int t = 0, i = 0, j = 0, flag = 0, n, te = 0, d = 0;
		n = strlen(a);
		for (i = 0; i < n; i++) {
			if (a[i] == '.') {
				t = i + 1;
			}
		}
		flag = 1;
		for (i = t; i < n; i++) {
			if (a[i] != '0') {
				d = i;
				flag = 0;
				break;
			}
		}
		if (flag) {
			printf("0\n");
		}
		else {
			for (j = d; j < n; j++) {
				printf("%c", a[j]);
			}
			puts("");
		}
	}
	return 0;
}
#endif