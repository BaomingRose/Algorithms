/*题目描述
A国部署的反导系统遇到了一个致命BUG，那就是每一次发射的拦截导弹的飞行高度都将只能小于等于上一枚导弹的飞行高度，
第一次发射的拦截导弹的飞行高度可以看作是足够大。对于A国，这是一件很严重的问题，这意味着A国的防空系统面临空前危机。
通过对A国的军事部门计算机的入侵，A国还不知道敌对国B国刚才已经发现了这项BUG。更不知道，
在这项BUG的报告书上交到B国空军司令部那一刻，三分钟后B国的全体高级空军军官已经在作战室讨论作战方案。
如果战争真的开始，B国将依次派出n架战斗机A国将依次发射拦截导弹，这n架飞机的飞行高度分别是h1h2h3.....hn。
B国将要充分利用这项漏洞，考虑到这么一种情况，假设只要A国的导弹的飞行高度大于等于B国飞机就能百分之百地锁定并击落，
那么B国，最少将会有几架不被击落飞机？

输入
第一行为T，表示有T组输入数据(T<200)。
每组数据第一行是n代表有n架飞机（1=<n<=20 000）。
接下来一行有n个数，分别代表n架飞机的飞行高度，飞机飞行高度maxh为(1<=maxh<=50 000)。

输出
对于每组测试数据，在每行中输出一个数。表示B国最少将会有几架未被击落飞机。

样例输入
2
1
1000
6
340 260 101 405 278 89
样例输出
0
2
*/

/*思路：找到一组数中有多少个数大于在该数之前的的某个数。 
可以把数组倒过来，从最后一个数往前，寻找最长不下降子序列，
然后数组的长度减去该子序列的长度即为所求*/

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[maxn],dp[maxn];
int b[maxn]; 
int main()
{
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++) cin>>a[i];
        memset(b,0,sizeof(0));
        for(i=0;i<n;i++)
        {
            b[n-1-i]=a[i];
        }
        memset(dp,0,sizeof(0));
        dp[0]=b[0];
        int pos,sum=1;
        for(i=1;i<n;i++)
        {
            pos=lower_bound(dp,dp+sum,b[i]+1)-dp;
            dp[pos]=b[i];
            sum=max(sum,pos+1);
        }
        cout<<n-sum<<endl;
    }
    return 0;
}
