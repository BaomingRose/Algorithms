/*多组测试样例
每行为一个不知道有多长的字符串 s ，然后是一个字符表示 c 要查询的字母，中间用空格隔开。
保证字符串中只有小写字母。
输出
输出要查询的字母在字符串中出现过的位置，字符串下标从一开始。
如果要查询的字母不在字符串中，输出 NO*/


#include<iostream>
using namespace std;
#include<string> 

int main()
{
	string str;
	char p;
	int flag = 1;
	while(cin >> str)
	{
		cin >> p;
		for(int i = 0; i < str.size(); ++i)
		{
			
			if(str[i] == p)
			{
				flag = 0;
				cout << i + 1 << " " ;
			}	
						
		}
		if(flag)
		{
			cout << "NO" ;
		}	
		cout << endl;
		flag = 1;
	}
	return 0;
}
