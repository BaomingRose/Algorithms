#if 0
/*����
�ж���������ݡ�
�����һ������������N��M�� N�����չ�����Ҫ����㷨�������� M�����չ��Ӵ����ֽ��1 < N < 100��1 < M < 10000��
����ڶ��У���N�������ֱ����ÿһ���㷨��ļ۸�
���
���һ�����������չ������������ٱ��㷨�顣*/

//̰�ģ��ӱ��˵ľ����ܵĶ���

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