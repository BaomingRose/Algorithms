/*
��ɯɯ��ѧ��ҵ�Ժ�ȥ����һ���������Ա����ÿ�춼����յ��ܶബ����������
�⼸����������һ�����Ϊ0 - 9�Ĵ��ӣ������и������ϰ�ߣ�
���Ǳ��밴�����Ǹ����ı��˳��������룬�������ͣ����ʮ������
��������ǰһ������������ǰû�б��·�����ú�һ����������
��ɯɯ��Уû�кú���ACM��������û�а취���㴬�ӵ�Ҫ���ϰ����ʮ�ֲ�����
���ܰ��������ⱻ����������ô��*/

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
