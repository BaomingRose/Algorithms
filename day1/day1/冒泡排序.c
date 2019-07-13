#if 0
#include<stdio.h>


void BubbleSort(int* a, int len)
{
	int i, j;
	int tmp;
	for (i = 0; i < len - 1; ++i)
	{
		for (j = 0; j < len - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
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
	BubbleSort(a, num);
	for (i = 0; i < num; ++i)
	{
		if (i)
			printf(" ");
		printf("%d", a[i]);
	}

	return 0;
}
#endif