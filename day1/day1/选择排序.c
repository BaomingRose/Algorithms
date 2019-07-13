#if 0
#include<stdio.h>

void SelectSort(int* a, int len)
{
	int i, j, tmp;
	int index;
	for (i = 0; i < len - 1; ++i)
	{
		index = i;
		for (j = i + 1; j < len; ++j)
		{
			if (a[j] < a[index])
				index = j;
		}
		if (index != i)
		{
			tmp = a[index];
			a[index] = a[i];
			a[i] = tmp;
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
	SelectSort(a, num);
	for (i = 0; i < num; ++i)
	{
		if (i)
			printf(" ");
		printf("%d", a[i]);
	}

	return 0;
}
#endif