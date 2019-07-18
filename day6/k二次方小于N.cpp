/*快帮数学不好的刘莎莎解决这个问题吧
得到一个正整数n，请输出有几个正整数k满足 k^k ≤ n*/

#include<iostream>
using namespace std;
#include<cmath>

int test(long long int N)
{
	int i; 
	for(i = 1; pow(i , i) <= N; ++i);
	return i - 1;
}

int main()
{
	long long int N;
	while(cin >> N)
	{
		cout << test(N) << endl;
	}
	return 0;
}
