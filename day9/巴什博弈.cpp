/*一堆石子，一次取一个至m个，最后取光者获胜 
输入数据首先包含一个正整数C(C<=100)，表示有C组测试数据。 
每组测试数据占一行，包含两个整数n和m（1<=nm<=1000），n和m的含义见题目描述。
如果先走的人能赢，请输出“first”，否则请输出“second”，每个实例的输出占一行。*/


#include<iostream>
using namespace std;

int main() {
    int num; 
    cin >> num;
    int m, n;
    while(num--) {
        cin >> m >> n;
        if(m % (n + 1) == 0)
            cout << "second" << endl;
        else
            cout << "first" << endl;
    }
    return 0;
}
