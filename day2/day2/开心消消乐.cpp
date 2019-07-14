/*鱼鱼是开心消消乐的忠实粉丝，奈何鱼鱼智商爆表，觉得开心消消乐过于简单，
于是便自创了独门消消乐，独乐乐不如众乐乐，于是他想和你一起玩这个游戏。
这个游戏的规则如下：假设你有一个长度为N的数字序列，
序列的每个位置上都有一个数字，你可以任意选取两个相同并且相邻的数字消掉，
每次消掉两个数字就会获得1分。由于数字在序列中具有一个相对位置，
所有当消掉数字时，便会出现空位，后面的数字就会向前移动，补齐空位。
作为一名资深的玩家，你想获得尽可能高的分数。*/

//堆栈

#if 0

#include <stdio.h>
int stack[100007];
int main()
{
	int top = 0;
	int n;

	while (~scanf("%d", &n))
	{
		top = 0;
		int temp;
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &temp);
			if (!top)
			{
				stack[++top] = temp;
			}
			else {
				if (temp == stack[top])
				{
					top--;
					sum++;
				}
				else
				{
					stack[++top] = temp;
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}

#endif
