/*给你一个整数N，你可以执行如下操作，
1：如果N能被2整除，用N/2代替N。
2：如果N能被3整除，用2N/3代替N。
3:  如果N能被5整除  用4N/5代替N。
你的任务是通过上述操作，求出将N变成1所需要的最小操作次数。*/

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
