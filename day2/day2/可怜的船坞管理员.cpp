/*
刘莎莎大学毕业以后去当了一个船坞管理员，她每天都会接收到很多船进出的请求。
这几天她遇到了一个编号为0 - 9的船队，他们有个奇葩的习惯，
就是必须按照他们给出的编号顺序进出船坞，船坞可以停下这十条船，
但船坞在前一条船开出船坞前没有别的路可以让后一条船开出，
刘莎莎在校没有好好做ACM的题所以没有办法满足船队的要求，老板对她十分不满。
你能帮助她避免被开除的命运么？*/

#if 0
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int stack[15];
	int top = 0;
	int n;
	int a[16], b[16];
	char ch1[50];

	while (~scanf("%d", &n))
	{
		top = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%1d", &a[i]);
		}

		for (int i = 0; i < n; ++i)
		{
			scanf("%1d", &b[i]);
		}
		stack[0] = -10;
		stack[++top] = a[0];
		ch1[0] = 'i';
		int k = 1;
		int t = 0;
		for (int i = 1; i < n;)
		{
			if (stack[top] == b[t])
			{
				t++;
				top--;
				ch1[k++] = 'o';
			}else
			{
				stack[++top] = a[i];
				ch1[k++] = 'i';
				i++;
			}
		}
		if (top > 0) {
			while (stack[top] == b[t])
			{
				--top, ++t;
				ch1[k++] = 'o';
			}
		}
		if (top > 0)
		{
			printf("No.\n");
			printf("Finish\n");
		}else
		{
			printf("Yes.\n");
			for (int i = 0; i < k; ++i)
			{
				if (ch1[i] == 'i') printf("In\n");
				if (ch1[i] == 'o') printf("Out\n");
			}
			cout << "Finish" << endl;
		}
	}
	return 0;
}

#endif
