#if 0

/*��һ�а���һ��������n(1 �� n �� 5000000)��
�ڶ��а���n������������������֮���ɿո�ֿ���
��֤ÿ��������С��100000��*/

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