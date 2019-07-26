/*��Ŀ����
People in Silverland use coins.They have coins of value A1A2A3...An Silverland dollar.
One day Tony opened his money-box and found there were some coins.
He decided to buy a very nice watch in a nearby shop. 
He wanted to pay the exact price(without change) and he known the price would not more than m.
But he didn't know the exact price of the watch.
You are to write a program which reads nmA1A2A3...An and C1C2C3...Cn corresponding to the number of 
Tony's coins of value A1A2A3...An then calculate how many prices(form 1 to m) Tony can pay use these coins.
����
The input contains several test cases. 
The first line of each test case contains two integers n(1<=n<=100)m(m<=100000).
The second line contains 2n integers denoting A1A2A3...AnC1C2C3...Cn (1<=Ai<=1000001<=Ci<=1000). 
The last test case is followed by two zeros.
���
For each test case output the answer on a single line.
��������
3 10
1 2 4 2 1 1
2 5
1 4 2 1
0 0
�������
8
4
*/ 


/*
	���������ĵط����ǽ����ر�������������˸ı䣬
    ��Ҫ����ÿһ�����ӵļ�ֵ�ᷢ���ı䣬�������ؼ��ĵط���
    ����ļ�ֵ�Ͳ����Ǹ��������ǽ���һ�����ͨ�����������ж���������Ƿ��ܹ��ﵽ��
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
//��ȫ����
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
//���ر���
void multilpack(int weight, int number, int value)
{
    //��һ��������� ��������Ʒ���е�������С�ڱ����������Ļ�
    //��ô���ڱ������� �����Ʒ�ǿ���ȡ���޴�
    if (bag <= number * weight)
    {
        completepack(weight, value);
        return;
    }
    //�������������Χ�ľ�ֻ��ʹ��01���� Ȼ��ʹ�ö����Ƶķ���
    //��ÿһ���͵ı�������һ������
    //���������ηֱ�ʹ�ö��ر�����
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
