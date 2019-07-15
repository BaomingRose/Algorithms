/*珊珊是个喜欢买买买的女孩子，今天她想去商店买衣服，
但她有选择恐惧症不知道去哪一家店，于是她想了个办法。
她给n个商店编号（编号为 1~n），从第 1 家店开始数，
一直数到 m，数到 m 的店不在她的选择范围内，剩下的店再接着从 1 开始数。
这样一直重复，最后剩下哪家店，她就去那家店买衣服。
你能告诉珊珊她该去编号为多少的店买衣服么？*/

#include<iostream>
using namespace std;
#include<list> 
 
int main()
{
	list<int> s;
	int m, n;
	while(cin >> n >> m )
	{
		if(m == 0 && n == 0)
			break;
		s.clear();
		for(int i = 1; i <= n; ++i)
			s.push_back(i);
		list<int>::iterator it = s.begin();
		while(s.size() > 1)
		{
			for(int i = 1; i < m; ++i)
			{
				it++;
				if(it == s.end())
					it = s.begin();
			}
			it = s.erase(it);
			if(it == s.end())
				it = s.begin();
		}
		
		cout << s.front() << endl;
	}
	return 0;
}
