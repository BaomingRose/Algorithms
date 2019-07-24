/*C国的死对头A国这段时间正在进行军事演习，
所以C国间谍头子Derek和他手下Tidy又开始忙乎了。
A国在海岸线沿直线布置了N个工兵营地Derek和Tidy的任务就是要监视这些工兵营地的活动情况。
由于采取了某种先进的监测手段，所以每个工兵营地的人数C国都掌握的一清二楚每个工兵营地的人数都有可能发生变动，
可能增加或减少若干人手但这些都逃不过C国的监视。 
中央情报局要研究敌人究竟演习什么战术所以Tidy要随时向Derek汇报某一段连续的工兵营地一共有多少人
例如Derek问:“Tidy马上汇报第3个营地到第10个营地共有多少人!”Tidy就要马上开始计算这一段的总人数并汇报。
但敌兵营地的人数经常变动，而Derek每次询问的段都不一样，所以Tidy不得不每次都一个一个营地的去数，
很快就精疲力尽了，Derek对Tidy的计算速度越来越不满:"你个死肥仔，算得这么慢，我炒你鱿鱼!”
Tidy想：“你自己来算算看，这可真是一项累人的工作!我恨不得你炒我鱿鱼呢!”无奈之下，
Tidy只好打电话向计算机专家Windbreaker求救Windbreaker说：“死肥仔，叫你平时做多点acm题和看多点算法书，
现在尝到苦果了吧!”Tidy说："我知错了。。。"但Windbreaker已经挂掉电话了。Tidy很苦恼，
这么算他真的会崩溃的，聪明的读者，你能写个程序帮他完成这项工作吗？不过如果你的程序效率不够高的话，
Tidy还是会受到Derek的责骂的. */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
 
const int maxn = 50005;
int tree[maxn];
int T, N;
 
int lowbit(int x) {
    return x & (-x);
}
 
void update(int x, int num) { 
    for(int i = x; i <= N; i += lowbit(i)) {
        tree[i] += num;
    }
}
 
int getSum(int x) {
    int res = 0;
    for(int i = x; i > 0; i -= lowbit(i)) {
        res += tree[i];
    }
    return res;
}
 
int main()
{
    cin >> T;
    int cnt = 0;
    while(T--) {
        cin >> N;
        memset(tree, 0, sizeof tree);
        int tmp;
        for(int i = 1; i <= N; i++) {
            cin >> tmp;
            update(i, tmp);
        }
        cout << "Case " << ++cnt << ':' << endl;
        string s;
        int x, y;
        while(cin >> s && s[0] != 'E') { 
            if(s[0] == 'Q') {
                cin >> x >> y;
                cout << getSum(y) - getSum(x-1) << endl;
            }
            else if(s[0] == 'A') {
                cin >> x >> y;
                update(x, y);
            }
            else {
                cin >> x >> y;
                update(x, -y);
            }
        }
    }
    return 0;
}

/*测试样例：1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End  */ 
