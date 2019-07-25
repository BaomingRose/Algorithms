/*有两堆石子，数量任意，可以不同。游戏开始由两个人轮流取石子。
游戏规定，每次有两种不同的取法，一是可以在任意的一堆中取走任意多的石子；
二是可以在两堆中同时取走相同数量的石子。最后把石子全部取完者为胜者。
现在给出初始的两堆石子的数目，如果轮到你先取，假设双方都采取最好的策略，问最后你是胜者还是败者？
输出也有若干行，如果最后你是败者，则为0，反之，输出1*/

#include<iostream>
using namespace std;
#include<cmath>

const double ep1 = (sqrt(5.0) - 1.0) / 2.0;
const double ep2 = (sqrt(5.0) + 1.0) / 2.0;

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) && (m || n)) {
        if(m > n) {
            int tmp;
            tmp = m, m = n, n = tmp;
        }
        int id = m * ep1;
        int tmp1 = ep2 * id, tmp2 = tmp1 + id;
        int tmp3 = ep2 * (id + 1), tmp4 = tmp3 + id + 1;
        if(tmp1 == m && tmp2 == n)  cout << "0" << endl;
        else if(tmp3 == m && tmp4 == n) cout << "0" << endl;
        else    cout << "1" << endl;
    }
    return 0;
}
