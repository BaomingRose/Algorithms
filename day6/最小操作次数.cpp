/*����һ������N�������ִ�����²�����
1�����N�ܱ�2��������N/2����N��
2�����N�ܱ�3��������2N/3����N��
3:  ���N�ܱ�5����  ��4N/5����N��
���������ͨ�����������������N���1����Ҫ����С����������*/

#include<iostream>
using namespace std;


int minExe(long long int N)
{
	int count = 0;
	while (N % 2 == 0 || N % 3 == 0 || N % 5 == 0)
	{
		if (N % 2 == 0)
		{
			N /= 2;
			++count;
		}
		if (N % 3 == 0)
		{
			N = N * 2 / 3;
			++count;
		}
		if (N % 5 == 0)
		{
			N = N * 4 / 5;
			++count;
		}
	}
	if (N == 1)
		return count;
	return -1;
}
int main()
{
	long long int N;
	int num;
	int count;
	cin >> num;
	while (num--)
	{
		cin >> N;
		cout << minExe(N) << endl;
	}

	return 0;
}
