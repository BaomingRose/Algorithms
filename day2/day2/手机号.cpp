/*AT&T 推出了一项服务——手机短号
每个月只要 5 块钱，手机短号互打免费。
已知 11 位数的手机号码，办理短号后，对应的短号就是 029 + 手机号码后 6 位
例如： 15619213595 -> 029213595
给你一个 11 位数的手机号码，请你找出对应的手机短号。*/

#if 0
#include<iostream>
using namespace std;
#include<cstdio>

int main()
{
	char str[12];
	while (scanf("%s", str) != EOF)
	{
		printf("029%s\n", str + 5);
	}

	return 0;
}
#endif