/*������ſ�ʼ��Ҳ��������ֹ��
������������ʽ :Ay1^2 + By2^2 + Cy3^2 + Dy4^2 = 0��
�����ĸ�����A��B��C��D����Ҫ�������ҵ�4������y1 y2 y3 y4ʹ��������ʽ������
������ж������ʹ��������ʽ���������ﱣ֤y1 y2 y3 y4�ķ�ΧΪ[-100 100]�Ҳ�Ϊ�㡣*/

#if 0
#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int y1, y2, y3, y4;
	int count = 0;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF)
	{
		for (y1 = -100; y1 <= 100; ++y1)
		{
			for (y2 = -100; y2 <= 100; ++y2)
			{
				for (y3 = -100; y3 <= 100; ++y3)
				{
					for (y4 = -100; y4 <= 100; ++y4)
					{
						if (a*y1*y1 + b * y2*y2 + c * y3*y3 + d * y4*y4 == 0)
						{
							++count;
						}
					}
				}
			}
		}
		cout << count << endl;
	}

	return 0;
}
#endif


#if 0

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int f1[1000005];        //�������������
int f2[1000005];        //��������Ǹ���

int main()
{
	int i, j, k, sum;
	int a, b, c, d;

	while (scanf("%d %d %d %d", &a, &b, &c, &d) != EOF)
	{
		//abcdȫ������0����С��0���϶��޽⡣Ҫ�����������Ȼ��ʱ
		if (a > 0 && b > 0 && c > 0 && d > 0 || a < 0 && b < 0 && c < 0 && d < 0)
		{
			printf("0\n");
			continue;
		}
		memset(f1, 0, sizeof(f1));
		memset(f2, 0, sizeof(f2));
		for (i = 1; i <= 100; i++)
		{
			for (j = 1; j <= 100; j++)
			{
				k = a * i * i + b * j * j;
				if (k >= 0) f1[k]++;    //k>=0 f1[k]++
				else f2[-k]++;          //k<0  f2[k]++
			}
		}
		sum = 0;
		for (i = 1; i <= 100; i++)
		{
			for (j = 1; j <= 100; j++)
			{
				k = c * i * i + d * j * j;
				if (k > 0) sum += f2[k];        //��kΪ�������ϵ�f2[k]
				else sum += f1[-k];             //��kΪ�������ϵ�f1[k]
			}
		}
		printf("%d\n", 16 * sum); //ÿ���������и��������2^4��
	}

	return 0;
}

#endif