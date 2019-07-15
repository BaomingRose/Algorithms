/*鹏鹏爱吃水果，所以他经常去水果店打包水果回家。但是鹏鹏的买水果方式和别人不一样，
他每次都会把所有的水果套餐全部买一遍，但是水果套餐里面有重复的水果。
作为一个完美主义者，鹏鹏不喜欢把同一样水果吃两遍。
鹏鹏说你要是能帮助他找到他点的所有水果套餐中的不重复不漏掉的水果，
多出来的水果就归你所有。你能帮助鹏鹏吗。*/


#include<iostream>
using namespace std;
#include<set>
#include<string>

int main()
{
	set<string> setFruit;
	int num;
	string str;
	while(cin >> num)
	{
		for(int i = 0; i < num; ++i)
		{
			cin >> str;
			setFruit.insert(str);
		}
		cout << setFruit.size() << endl;
		setFruit.clear();
	}
}
