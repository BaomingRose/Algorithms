/*��Ŀ����
�������ĸ�ľ�����һ�ֱ������黳������Сд��ĸ��ɡ�
���������ó��������İ�֮��������㣬���������������Գ��Ӿ���ı߳���
���жԳƾ�����һ��k*k�ľ�������Ԫ�ع��ڴ����½ǵ����ϽǵĶԽ��߶Գơ� 
�����������3* 3�ľ����ǶԳƾ��� 
cbx 
cpb 
zcc
����
�������ݡ�ÿһ���һ����һ�� n (0<n<=1000)������n�У�ÿһ����n����ĸ���м�û�пո�������n=0������
���
ÿ������������ĶԳƾ���ı߳���
��������
3
abx
cyb
zca
4
zaba
cbab
abbc
cacq
0
�������
3
3
*/

/*
	����ط���ֱ�Ӿ��Ǵ𰸵�˼·�ˣ���һ�ֵ���ķ�����ǰ���ƣ����Խ��ߴ洢������
    ���ǵ�ǰ�ܴ洢�������ľ���
    ״̬ת�Ʒ��̾��� dp[i][j] �� dp[i - k][j]�� dp[i][j - k] �Ƿ����Ȼ�������洢
    ����������һ�����ɾ��� ÿһ������ֻ�Ǵ洢��������ܹ����ܵ����ֵ��

    �Լ���İ취û�п��ǵ�״̬��Ǩ�ƣ�Ҳ����û�п��ǵ�״̬��״̬֮�����ϵ�������չ�ֳ����ˡ�
    ��ÿһ��ֵ�洢��dp[i - 1][j + 1] �ϣ�Ȼ����һ�ζ��������֤��
    
*/
#include <iostream>
#include <cstring>
using namespace std;

int n;

const int maxn = 1005;
char ch[maxn][maxn];
int dp[maxn][maxn];

int main() {
    //freopen("test2.in", "r", stdin);
    //freopen("test2.out", "w", stdout);
    while (cin >> n && n) {
        getchar();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> ch[i][j];
                dp[i][j] = 1;
            }
            getchar();
        }
        int Max = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = n; j >= 1; j--) {
                if (i == 1 || j == n)
                    continue;
                int tmp = dp[i - 1][j + 1];
                for (int k = 1; k <= tmp; k++) {
                    if (ch[i - k][j] == ch[i][j + k])
                        dp[i][j]++;
                    else
                        break;
                }
                Max = max(Max, dp[i][j]);
            }
        }
        printf("%d\n", Max);
    }
    return 0;
}
