/*小颖和小静是一对小姐妹，所以她们喜欢所有事都成双成对
深受老师宠爱的小颖从老师那里拿来了一块画板，画板上刻着很多数字。
小颖和小静看到画板上的偶数，希望能够将画板上存在的偶数凑对，
凑对的偶数相加等于她们最喜欢的数字L，但是画板上的数字有很多，
而且会出现重复的数字，
她们希望你能编写一个程序来计算画板上的偶数能够凑出多少对她们喜欢的数字*/

//哈希表


#if 0
#include <cstdio>
#include <iostream>
#include <cstring>
#include<cstdlib>
using namespace std;
int num[10007];
int main()
{
	int n, l;

	while (~scanf("%d %d", &n, &l)) {
		memset(num, 0, sizeof num);
		int temp;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &temp);
			num[temp]++;
		}
		// for (int i = 0; i < 10; ++i) cout << num[i] << " ";
		if (l & 1) {
			printf("what a pity!!!\n");
			continue;
		}
		int sum = 0;
		for (int i = 0; i <= 10000; i += 2) {
			if (i <= l) {
				if (num[i] && num[l - i]) {
					if (i != l - i) {
						while (num[i] && num[l - i]) {
							num[i]--, num[l - i]--, sum++;
						}
					}
					else {
						while (num[i] > 2) {
							num[i] -= 2;
							sum++;
						}
					}
				}
			}
			else break;
		}
		if (sum == 0) printf("what a pity!!!\n");
		else printf("%d\n", sum);
	}
	return 0;
}
#endif