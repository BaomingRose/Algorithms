#if 0

/*居居倩来到了一个n*m的黑白格地板上，她想不重复地走完所有白格，
但她不知道最少要多久才能走完，你能帮帮她么？
有以下两种走法
1.从白格隔一个黑格直线跳到下一个白格，耗时3分钟
2.从白格走到斜上或斜下方的白格，耗时4分钟
已知黑白格地板的左上角为白格，居居倩也将在左上角开始她的游戏*/

//尽可能少的斜着走，分析后，只需走一个斜着

#include<stdio.h>

int minTime(int white)
{
	return (white - 2) * 3 + 4;
}

int main()
{
	int m, n;		//行数、 列数
	int white;		//白子个数
	scanf("%d%d", &m, &n);
	white = (m * n) / 2;
	printf("%d", minTime(white));

	return 0;
}

#endif