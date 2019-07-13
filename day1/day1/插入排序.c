#if 0
#include<stdio.h>

void InsertSort(int* a, int len)
{
	int i, j;
	int tmp;
	for (i = 1; i < len; ++i)
	{
		tmp = a[i];
		for (j = i; j > 0 && a[j - 1] > tmp; --j)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}



int main()
{
	int num, a[1000] = { 0 };
	int i;
	scanf("%d", &num);
	for (i = 0; i < num; ++i)
	{
		scanf("%d", &a[i]);
	}
	InsertSort(a, num);
	for (i = 0; i < num; ++i)
	{
		if (i)
			printf(" ");
		printf("%d", a[i]);
	}

	return 0;
}
#endif