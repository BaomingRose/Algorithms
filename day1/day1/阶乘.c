#if 0
#include<stdio.h>

int fac(int num)
{
	if (num == 1)
		return 1;
	return num * fac(num - 1);
}

int factor(int num)
{
	int i, ret = 1;
	for (i = 1; i <= num; ++i)
	{
		ret *= i;
	}
	return ret;
}

int main()
{
	int num;
	scanf("%d", &num);
	printf("%d\n", factor(num));
	printf("%d\n", fac(num));
	return 0;
}
#endif