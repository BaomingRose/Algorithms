/* 
����n(n < 10000)�����֣�Ҫ��ÿ������ֻ�����һ�Σ���������Ϊ�ǵݼ���
*/

#include<iostream>
using namespace std;
#include<set>

int main()
{
	set<int> si;
	int elem;
	int num;
	while(cin >> num)
	{
		for(int i = 0; i < num; ++i)
		{
			cin >> elem;
			si.insert(elem);
		}
		set<int>::iterator it;
		for(it = si.begin(); it != si.end(); ++it)
		{
			if(it != si.begin())
				cout << " ";
			cout << *it;
		}
		cout << endl;
		si.clear();
	}
	return 0;
}
