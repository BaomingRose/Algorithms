/*题目描述
对于吃货来说，过年最幸福的事情就是吃，没有之一！
但是对于红红来说，卡路里（热量）是天敌。
红红想要一个健美的身材，所以需求舒舒设定了一个健康且幸福的食谱计划。
为了方便食谱的制作，舒舒给红红的每日清单上面描述了当天她想吃的食物给他的幸福度，以及会增加卡路里。

输入
	输入包含多组测试用例。
	每组数据以一个整数n开始，表示每天的食物清单有n种食物。
	接下来n行，每行两个整数a和b，其中a表示这种食物可以带给红红的幸福值（数值越大，越幸福），b表示红红吃这种食物会吸收的卡路里量。
	最后是一个整数m，表示红红一天吸收的卡路里不能超过m。
	 [Technical Specification]
	1. 1 <= n <= 100
	2. 0 <= ab <= 100000
	3. 1 <= m <= 100000
输出
对每份清单，输出一个整数，即满足卡路里吸收量的同时，红红可获得的最大幸福值。

样例输入
3
3 3
7 7
9 9
10
5
1 1
5 3
10 3
6 8
7 5
6
样例输出
10
20
*/


#include<iostream>
using namespace std;
#include<cmath>
#include<cstring>

int data[100001];
int weight[101];
int value[101];

int main() {
	int n, size;	//size 背包容量 	n 物品个数 
	int i, j;
	while(cin >> n) { 
		memset(data, 0, sizeof(data));
		
		for(i = 1; i <= n; ++i) {
			cin >> value[i] >> weight[i];
		}
		
		cin >> size;
		
		for (i = 1; i <= n; i++) {
			for (j = weight[i]; j <= size; j++) {
				data[j] = max(data[j], data[j - weight[i]] + value[i]);
			}
		}
		cout << data[size] << endl;
	}
	return 0;
	
}
