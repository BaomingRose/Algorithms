/*Сӱ��С����һ��С���ã���������ϲ�������¶���˫�ɶ�
������ʦ�谮��Сӱ����ʦ����������һ�黭�壬�����Ͽ��źܶ����֡�
Сӱ��С�����������ϵ�ż����ϣ���ܹ��������ϴ��ڵ�ż���նԣ�
�նԵ�ż����ӵ���������ϲ��������L�����ǻ����ϵ������кܶ࣬
���һ�����ظ������֣�
����ϣ�����ܱ�дһ�����������㻭���ϵ�ż���ܹ��ճ����ٶ�����ϲ��������*/

//��ϣ��


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