/*�����ѧ���õ���ɯɯ�����������
�õ�һ��������n��������м���������k���� k^k �� n*/

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
