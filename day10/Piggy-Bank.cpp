/*题目描述
Before ACM can do anything a budget must be prepared and the necessary financial support obtained. 
The main income for this action comes from Irreversibly Bound Money (IBM). The idea behind is simple. 
Whenever some ACM member has any small money he takes all the coins and throws them into a piggy-bank.
You know that this process is irreversible the coins cannot be removed without breaking the pig. 
After a sufficiently long time there should be enough cash in the piggy-bank to pay everything that needs to be paid.
But there is a big problem with piggy-banks. It is not possible to determine how much money is inside.
So we might break the pig into pieces only to find out that there is not enough money. 
Clearly we want to avoid this unpleasant situation. The only possibility is to weigh the piggy-bank and try to guess how many coins are inside. 
Assume that we are able to determine the weight of the pig exactly and that we know the weights of all coins of a given currency. 
Then there is some minimum amount of money in the piggy-bank that we can guarantee. 
Your task is to find out this worst case and determine the minimum amount of cash inside the piggy-bank. We need your help. 
No more prematurely broken pigs!
输入
The input consists of T test cases. The number of them (T) is given on the first line of the input file. Each test case begins with a line containing two integers E and F. They indicate the weight of an empty pig and of the pig filled with coins. Both weights are given in grams. No pig will weigh more than 10 kg that means 1 <= E <= F <= 10000. On the second line of each test case there is an integer number N (1 <= N <= 500) that gives the number of various coins used in the given currency. Following this are exactly N lines each specifying one coin type. These lines contain two integers each Pand W (1 <= P <= 50000 1 <= W <=10000). P is the value of the coin in monetary units W is it's weight in grams.
输出
Print exactly one line of output for each test case. The line must contain the sentence "The minimum amount of money in the piggy-bank is X." where X is the minimum amount of money that can be achieved using coins with the given total weight. If the weight cannot be reached exactly print a line "This is impossible.".
样例输入
3
10 110
2
1 1
30 50
10 110
2
1 1
50 30
1 6
2
10 3
20 4
样例输出
The minimum amount of money in the piggy-bank is 60.
The minimum amount of money in the piggy-bank is 100.
This is impossible.
*/

/*
	这道题是一个完全背包的裸题，对于这道题而言更加神奇的地方就在于其实求最小值而不是求最大值
    所以在最先开始初始化的时候不应该去初始化为0，而应该初始化为无穷大
    而千万不要忘记了再初始化的时候一定要对第一个状态进行一个单独赋值是等于0，还是等于无穷大，这个等到时候再看。
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

    using namespace std;

int _beg,_end;
const int maxn = 505;
int v[maxn],w[maxn];
int dp[10010];

int main()
{
    int T;
    cin >> T;
    while (T--) {

        scanf("%d %d",&_beg,&_end);
        int bottle = _end - _beg;
        int n;
        scanf("%d",&n);

        for (int i = 1; i <= n; i++){
            scanf("%d %d",&v[i],&w[i]);
        }
        
        memset(dp,0x3f3f3f3f,sizeof dp);
        dp[0] = 0;

        for (int i = 1; i <= n;i ++) {
            for (int j = w[i]; j <= bottle; j++) {
                dp[j] = min(dp[j],dp[j - w[i]] + v[i]);
            }
        }

        if (dp[bottle] != 0x3f3f3f3f)
            cout << "The minimum amount of money in the piggy-bank is " << dp[bottle] << "." << endl;
        else
            cout << "This is impossible." << endl;
        
    }
    return 0;
}
