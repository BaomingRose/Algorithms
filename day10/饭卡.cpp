/*��Ŀ����
�������һ����Ʒ֮ǰ�����ϵ�ʣ������ڻ����5Ԫ����һ�����Թ���ɹ�����ʹ����������Ϊ������
�����޷����򣨼�ʹ����㹻�������Դ�Ҷ�ϣ������ʹ���ϵ�������١�
ĳ�죬ʳ������n�ֲ˳��ۣ�ÿ�ֲ˿ɹ���һ�Ρ���֪ÿ�ֲ˵ļ۸��Լ����ϵ���
�����ٿ�ʹ���ϵ����Ϊ���١�
����
�������ݡ�����ÿ�����ݣ�
��һ��Ϊ������n����ʾ�˵�������n<=1000��
�ڶ��а���n������������ʾÿ�ֲ˵ļ۸񡣼۸񲻳���50��
�����а���һ��������m����ʾ���ϵ���m<=1000��
n=0��ʾ���ݽ�����

���
����ÿ���������һ�а���һ����������ʾ���Ͽ��ܵ���С��
��������
1
50
5
10
1 2 3 2 1 1 2 3 2 1
50
0
�������
-45
32
*/


/*
	һά���������������������01����������ֱ����ģ��
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
	�ڶ��ַ��� 
	��ά����ֱ����ģ��
*/
/*
	���������ĵط������� ������������ڼ�ֵ�غ�����һ�����Զ����������Ծ���ֻ���غϵ�ȥд״̬ת�Ʒ�����
    ������Ҫע���������������İ취���ǽ����һ����Ʒ����ʣ�µ�����Ǯȥ���������ܳ����ù�����Ǯ��
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
        //����������һά�������鲻̫һ�����ǣ�һά���������ǲ����ж���Ʒ���ƵĲ�����
        //��˼���� �Ҷ�ά����������n-1������Ȼ��������һ����������Ǯ��dp[i - 1][j]
        //��һά��������ֻ��һ������������������Ĳ���dp[i]
        //�������������һ���������ͨ�������n-1����Ʒ��������ټ�ȥ��Ӧ��Ǯ�����õ����մ𰸡�
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
