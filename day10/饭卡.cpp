/*题目描述
如果购买一个商品之前，卡上的剩余金额大于或等于5元，就一定可以购买成功（即使购买后卡上余额为负），
否则无法购买（即使金额足够）。所以大家都希望尽量使卡上的余额最少。
某天，食堂中有n种菜出售，每种菜可购买一次。已知每种菜的价格以及卡上的余额，
问最少可使卡上的余额为多少。
输入
多组数据。对于每组数据：
第一行为正整数n，表示菜的数量。n<=1000。
第二行包括n个正整数，表示每种菜的价格。价格不超过50。
第三行包括一个正整数m，表示卡上的余额。m<=1000。
n=0表示数据结束。

输出
对于每组输入输出一行包含一个整数，表示卡上可能的最小余额。
样例输入
1
50
5
10
1 2 3 2 1 1 2 3 2 1
50
0
样例输出
-45
32
*/


/*
	一维滚动数组的做法，由于是01背包，所以直接套模板
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int d[1010];
    int dp[1010];
    while (cin >> n && n)
    {
        memset(d, 0, sizeof(d));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            cin >> d[i];
        }
        int p;
        cin >> p;
        sort(d + 1, d + n + 1);
        if (p < 5)
        {
            cout << p << endl;
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                for (int j = p - 5; j >= d[i]; j--)
                {
                    dp[j] = max(dp[j], dp[j - d[i]] + d[i]);
                }
            }
            cout << p - dp[p - 5] - d[n] << endl;
        }
    }
    return 0;
}

/*
	第二种方法 
	二维数组直接套模板
*/
/*
	这道题神奇的地方就在于 其的重量限制于价值重合在了一起，所以对于这道题而言就是只能重合的去写状态转移方程了
    另外需要注意的是最后输出结果的办法，是将最后一个物品交给剩下的最大的钱去购买，这样能彻底用光最后的钱财
*/


#if 0

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int n,m;
const int maxn = 1010;
int num[maxn],dp[maxn][maxn];

int main()
{
    while (cin >> n && n) {
        for (int i = 1; i <= n; i++) {
            cin >> num[i];
        }
        cin >> m;
        sort(num + 1, num + 1 + n);
        if (m < 5) {
            cout << m << endl;
            continue;
        }
        memset(dp,0,sizeof dp);
        //这里与上面一维滚动数组不太一样的是，一维滚动数组是不能有对物品限制的操作。
        //意思就是 我二维数组可以算出n-1个数，然后算出最后一个数给出的钱数dp[i - 1][j]
        //而一维数组由于只有一个参数就是体积容量的参数dp[i]
        //所以下面多算了一个，最后再通过计算出n-1个物品的体积，再减去相应的钱数，得到最终答案。
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m - 5; j++) {
                if (j >= num[i]) {
                    dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - num[i]] + num[i]);
                }
                else dp[i][j] = dp[i - 1][j];
            }
        }
        cout << m - dp[n - 1][m - 5] - num[n] << endl;
    }
    return 0;
}

#endif
