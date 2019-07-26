/*题目描述
红红最近迷上了吃鸡，房间有n个配件，每一个配件的重量为c(<=1e3)，和价值为v(v <= 1e3)
假设红红刚落地就捡到一个三级包，容量为S，请问红红可以成为多肥的快递员？
输入
输入的第一行为T， 表示红红要跳T次伞。
每一组数据由三行组成。
第一行包含两个整数n s，分别表示数量和背包容量，第二行包含n个整数，表示每一个配件的价值。
第三行包含n个整数，表示每一个配件重量。
输出
对于每一组数据，输出红红可以多肥。
样例输入
1
10 10
1 3 5 7 9 11 13 15 17 19
19 17 15 13 11 9 7 5 3 1
样例输出
51
*/

#include<iostream>
using namespace std;
#include<cmath>
#include<cstring>

int data[12881];
int weight[3403];
int value[3403];

int main() {
	int num;
	cin >> num;
	int n, size;	//size 背包容量 	n 物品个数 
	int i, j;
	while(num--) { 
		memset(data, 0, sizeof(data));
		cin >> n >> size;
		for(i = 1; i <= n; ++i) {
			cin >> value[i];
		}
		for(i = 1; i <= n; ++i) {
			cin >> weight[i];
		}
		
		for (i = 1; i <= n; i++) {
			for (j = size; j >= weight[i] ; j--) {
				data[j] = max(data[j], data[j - weight[i]] + value[i]);
			}
		}
		cout << data[size] << endl;
	}
	return 0;
	
}
