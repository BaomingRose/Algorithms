/*有多堆物品两个人轮流从某一堆取任意多的物品，规定每次至少取一个，
多者不限，最后取光者获胜。
输入多组数据
第一行 输入 n ，代表有n堆物品
接下来n个数 代表每堆物品的数量*/

#include<iostream>
using namespace std;

int main() {
    int num, m;
    int res = 0;
    while(cin >> num) {
        for(int i = 0; i < num; ++i) {
            cin >> m;
            res ^= m;
        }
        if(res == 0) {
            cout << "second" << endl;
        } else {
            cout << "first" << endl;
        }
    }
    return 0;
}
