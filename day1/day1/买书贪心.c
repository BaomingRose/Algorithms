#if 0
/*输入
有多组测试数据。
输入第一行有两个整数N，M。 N代表苏公子想要买的算法书数量， M代表苏公子带的现金金额。1 < N < 100，1 < M < 10000。
输入第二行，有N个数，分别代表每一本算法书的价格。
输出
输出一个数，代表苏公子最多能买多少本算法书。*/

//贪心：从便宜的尽可能的多买

#include<stdio.h>

void Bubble(int* data, int num)
{
	int i, j, tmp;
	for (i = 0; i < num; ++i)
	{
		for (j = 0; j < num - 1 - i; ++j)
		{
			if (data[j] > data[j + 1])
			{
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int money, want, price[100] = { 0 };
	int i, sum = 0;
	while (scanf("%d%d", &want, &money) != EOF)
	{
		for (i = 0; i < want; ++i)
		{
			scanf("%d", &price[i]);
		}
		Bubble(price, want);
		for (i = 0; sum + price[i] <= money && i < want; ++i) {
			sum += price[i];
		}
		printf("%d\n", i);
		sum = 0;
	}

	return 0;
}
#endif