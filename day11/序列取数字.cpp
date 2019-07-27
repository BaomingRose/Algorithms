/*��Ŀ����
������һ�����У�ÿ�ο���ȡ����˵����ֻ������Ҷ˵����֡�һ��Ҫ��n��ȡ�ꡣ
�������i��ȡ��������x������Ի��i*x�ļ�ֵ������Ҫ�滮ȡ��˳��ʹ��õ��ܼ�ֵ֮�����
����
�������롣
��һ��һ������n(1<=n<=2000)��
����n��ÿ��һ������v(i)��(1<=v(i)<=1000)��
���
���һ�����֣���ʾ����ܼ�ֵ�͡�
��������
5
1
3
1
5
2
�������
43
��ʾ
���������±�˳��ȡ���� 1 5 2 3 4
ȡ��������˳��Ϊ��1 2 3 1 5
����ܼ�ֵ�ͣ�1x1 + 2x2 + 3x3 + 4x1 + 5x5 = 43.
*/

/*
	�����Ŀ���ǵ��͵�����DP����Ŀ�ˣ���һ�����������ֵ���ж�̬�滮����⣬���������״̬ת�Ʒ���
    dp[i][j] = max(dp[i + 1][j] + num[i] *(n + i - j),
    dp[i][j - 1] + num[j] * (n + i - j));

    �����Ψһ�ر����뵽���ǣ������Ŀ��һ�������������⣬
    ��˼���ǴӺ����״̬��ǰ���ƣ��⵱ʱ���Ҿ���ȫû���뵽�ˡ�
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
const int maxn = 2005;
int dp[maxn][maxn];
int num[maxn];

int main() {
    //freopen("test3.in", "r", stdin);
    //freopen("test3.out", "w", stdout);
    while (~scanf("%d", &n)) {
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &num[i]);
            dp[i][i] = num[i];
        }
        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                //������� n + i - j ��ʵһ��ʼ�ı��ξ��� n - (j - i + 1) + 1
                dp[i][j] = max(dp[i + 1][j] + num[i] * (n + i - j), dp[i][j - 1] + num[j] * (n + i - j));
            }
        }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}

