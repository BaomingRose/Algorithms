/*��Ŀ����
��֪����������ƥ�����ͣ��ֱ��ǡ�(���͡�)������[���͡�]����
����һ���ַ�����ֻ������ 4 �ַ��ţ����Ȳ�����100��
�������ƥ�����ŵ����������
����
�����ж���������ݣ�����0ʱ������
ÿ���������ֻ��һ�У�ֻ���� ' ( ' ��' ) '��  ' [ '��  ' ] ' ���ַ��ţ��ҳ��Ȳ�����һ��
���
ÿ������������һ�У����Ϊ����ƥ�����ŵ������Ŀ��
��������
((()))
()()()
()))()
([()])
0
�������
6
6
4
6
*/

#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 105;
int dp[maxn][maxn];
string V;
int main() {
    while (cin >> V, V[0] != '0') {
        int n = V.size();
        for (int i = 0; i <= n; i++) {
            memset(dp[i], 0, sizeof(dp[i]));
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (V[i] == '(' && V[j] == ')' || 
                V[i] == '[' && V[j] == ']') {
                    if (i + 1 > j - 1)
                        dp[i][j] = 2;
                    else
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                for (int k = i; k < j; k++) {
                    dp[i][j] = max(dp[i][j], 
                    dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        cout << dp[0][n - 1] << endl;
        V.clear();
    }
    return 0;
}
