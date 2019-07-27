/*题目描述
A subsequence of a given sequence is the given sequence with some elements (possible none) left out. 
Given a sequence X = < x1 x2 ... xm > another sequence Z = < z1 z2 ... zk > is a subsequence of X 
if there exists a strictly increasing sequence < i1 i2 ... ik > of indices of X such that for all j = 12...k x ij = zj. 
For example Z = < a b f c > is a subsequence of X = < a b c f b c > with index sequence < 1 2 4 6 >. 
Given two sequences X and Y the problem is to find the length of the maximum-length common subsequence of X and Y.
输入
A subsequence of a given sequence is the given sequence with some elements (possible none) left out.
Given a sequence X = < x1 x2 ... xm > another sequence Z = < z1 z2 ... zk > is a subsequence of X 
if there exists a strictly increasing sequence < i1 i2 ... ik > of indices of X such that for all j = 12...k x ij = zj. 
For example Z = < a b f c > is a subsequence of X = < a b c f b c > with index sequence < 1 2 4 6 >. 
Given two sequences X and Y the problem is to find the length of the maximum-length common subsequence of X and Y.
输出
For each set of data the program prints on the standard output the length of the maximum-length common subsequence 
from the beginning of a separate line.
样例输入
abcfbc         abfcab
programming    contest 
abcd           mnp
样例输出
4
2
0
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string s1, s2, tmp;

int main() {
    //freopen("test1.in", "r", stdin); 
    //freopen("test1.out", "w", stdout); 
    while (cin >> s1 >> s2) {
        if (s1.size() < s2.size()) {
            tmp = s1;
            s1 = s2;
            s2 = tmp;
        }
        int dp[s1.size() + 10][s1.size() + 10];
        memset(dp, 0, sizeof dp);
        int Max = 0;
        for (int i = 0; i < s2.size(); i++) {
            int k = i + 1;
            for (int j = 0; j < s1.size(); j++) {
                int l = j + 1;
                if (s1[j] == s2[i]) {
                    dp[k][l] = dp[k - 1][l - 1] + 1;
                }
                else
                    dp[k][l] = max(dp[k - 1][l], dp[k][l - 1]);
                Max = max(Max, dp[k][l]);
            }
        }
        cout << dp[s2.size()][s1.size()] << endl;
    }

    return 0;
}
