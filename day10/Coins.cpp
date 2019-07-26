/*题目描述
People in Silverland use coins.They have coins of value A1A2A3...An Silverland dollar.
One day Tony opened his money-box and found there were some coins.
He decided to buy a very nice watch in a nearby shop. 
He wanted to pay the exact price(without change) and he known the price would not more than m.
But he didn't know the exact price of the watch.
You are to write a program which reads nmA1A2A3...An and C1C2C3...Cn corresponding to the number of 
Tony's coins of value A1A2A3...An then calculate how many prices(form 1 to m) Tony can pay use these coins.
输入
The input contains several test cases. 
The first line of each test case contains two integers n(1<=n<=100)m(m<=100000).
The second line contains 2n integers denoting A1A2A3...AnC1C2C3...Cn (1<=Ai<=1000001<=Ci<=1000). 
The last test case is followed by two zeros.
输出
For each test case output the answer on a single line.
样例输入
3 10
1 2 4 2 1 1
2 5
1 4 2 1
0 0
样例输出
8
4
*/ 


/*
	这道题神奇的地方就是将多重背包的裸题进行了改变，
    主要就是每一次增加的价值会发生改变，这才是最关键的地方。
    这里的价值就不再是个数，而是进行一个打表，通过这个打表来判断这个重量是否能够达到。
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int n;
int bag;
bool dp[100040];
int value[105],number[105];
int cnt = 0;
void zeroonepack(int weight, int value)
{
    for (int j = bag; j >= weight; j--)
    {
        if (!dp[j] && dp[j - weight]){
            dp[j] = true;
            cnt ++;
        }
    }
}
//完全背包
void completepack(int weight, int value)
{
    for (int j = weight; j <= bag; j++)
    {
        if (!dp[j] && dp[j - weight]) {
            dp[j] = true;
            cnt ++;
        }
    }
}
//多重背包
void multilpack(int weight, int number, int value)
{
    //第一种情况就是 如果这件物品所有的重量是小于背包的重量的话
    //那么对于背包而言 这个物品是可以取无限大。
    if (bag <= number * weight)
    {
        completepack(weight, value);
        return;
    }
    //而超过的这个范围的就只能使用01背包 然后使用二进制的方法
    //将每一类型的背包进行一个分组
    //后面再依次分别使用多重背包。
    int k = 1;
    while (k < number)
    {
        zeroonepack(k * weight, k * value);
        number = number - k;
        k = k * 2;
    }
    zeroonepack(number * weight, number * value);
}

int main()
{
    while (cin >> n >> bag && n && bag) {
        for (int i = 1; i <= n; i++) {
            cin >> value[i];
        }

        for (int i = 1; i <= n;i ++) {
            cin >> number[i];
        }
        cnt = 0;
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        for (int i = 1; i <= n ;i ++) {
            multilpack(value[i],number[i],value[i]);
        }
        
        cout << cnt << endl;
    }

    return 0;
}
