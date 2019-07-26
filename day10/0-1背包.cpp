/*题目描述
Bessie has gone to the mall's jewelry store and spies a charm bracelet. 
Of course she'd like to fill it with the best charms possible from the N (1 ≤ N ≤ 3402) available charms.
Each charm i in the supplied list has a weight Wi (1 ≤ Wi ≤ 400) a 'desirability' factor Di (1 ≤ Di ≤ 100) 
and can be used at most once. Bessie can only support a charm bracelet whose weight is no more than M (1 ≤ M ≤ 12880).
Given that weight limit as a constraint and a list of the charms with their weights and desirability rating deduce the maximum possible sum of ratings.
输入
* Line 1: Two space-separated integers: N and M
* Lines 2..N+1: Line i+1 describes charm i with two space-separated integers: Wi and Di
输出
* Line 1: A single integer that is the greatest sum of charm desirabilities that can be achieved given the weight constraints
样例输入
4 6
1 4
2 6
3 12
2 7
样例输出
23
*/

#include<iostream>
using namespace std;
#include<cmath>

int data[12881];
int weight[3403];
int value[3403];

int main() {
	int n, size;	//size 背包容量 	n 物品个数 
	int i, j;
	cin >> n >> size;
	for (i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}
	for (i = 1; i <= n; i++) {
		for (j = size; j >= weight[i] ; j--) {
			data[j] = max(data[j], data[j - weight[i]] + value[i]);
		}
	}
	cout << data[size] << endl;
	return 0;
	
}
