#if 0

/*现在我们有一套独特的评级规则：
如果你的分数 X 满足 X = 4 * n + 1，即除以 4 余 1，那么你的分数为 A 等。
同样的如果你的分数满足 X = 4 * n + 3，那么你的分数为 B 等。
如果你的分数满足 X = 4 * n + 2，那么你的分数为 C 等。
如果你的分数是其他情况，那么为 D 等。
现在给出你的分数，你有一次修改自己分数的机会，当然不能太过分，所以这个修改被限制为：增加 0 或 1 或 2。
请考虑最佳情况给出自己能拿到的最佳评级。*/

#include<stdio.h>

char grade(int score)
{
	if ((score + 1) % 4 == 1 || (score + 2) % 4 == 1 || score % 4 == 1)
		return 'A';
	else
		return 'B';
}

int main()
{
	int score;
	scanf("%d", &score);
	printf("%c", grade(score));
	return 0;
	
}
#endif