/*���ϰ�����ǻۣ��ڴ����ʱ��ȥ��̯��Ӧ��ˮ����������֦�����ܣ�����ɶ�ġ�
�����ϰ��Ǹ����԰׳գ����������������Ҳ����������ˮ����
����Ҫ�����������ˮ�����ࡣ
���� N ��ˮ����ÿ��ˮ������һ�����ֺ�һ����𣬶����ַ����ҳ��Ȳ����� 20��*/
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
