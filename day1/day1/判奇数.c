#if 0

/*第一行包括一个正整数n(1 ≤ n ≤ 5000000)。
第二行包括n个正整数，两个整数之间由空格分开。
保证每个正整数小于100000。*/

#include<stdio.h>

int isOdd(int num)
{
	if (num & 1 == 1)
		return 1;
	else
		return 0;
}

int main()
{
	int n, i;
	int cout = 0;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		int num;
		scanf("%d", &num);

		if (isOdd(num))
			cout++;
	}
	printf("%d\n", cout);
	return 0;
}
#endif