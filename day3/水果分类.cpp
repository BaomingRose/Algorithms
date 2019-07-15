/*李老板很有智慧，在春天的时候去摆摊卖应季水果，例如荔枝，菠萝，桃子啥的。
但李老板是个电脑白痴，他用收银机总是找不到客人买的水果。
所以要求你帮他进行水果分类。
给你 N 种水果，每个水果都有一个名字和一个类别，都是字符串且长度不超过 20。*/
#include<iostream>
using namespace std;
#include<map>
#include<set>

int main()
{
	map<string,string> mapFruit;
	set<string> setFruit;
	string name, kind;
	int num;
	cin >> num;
	for(int i = 0; i < num; ++i)
	{
		cin >> name >> kind;
		setFruit.insert(kind);
		mapFruit.insert(pair<string,string>(name,kind));
	}
	set<string>::iterator its;
	map<string, string>::iterator itm;
	for(its = setFruit.begin(); its != setFruit.end(); ++its)
	{
		cout << *its << endl;
		for(itm = mapFruit.begin(); itm != mapFruit.end(); ++itm)
		{
			if(itm->second == *its)
			{
				 cout << "   |--- " << itm->first << endl;
			}
		}
	}
	return 0;
}
