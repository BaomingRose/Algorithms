/*ɺɺ�Ǹ�ϲ���������Ů���ӣ���������ȥ�̵����·���
������ѡ��־�֢��֪��ȥ��һ�ҵ꣬���������˸��취��
����n���̵��ţ����Ϊ 1~n�����ӵ� 1 �ҵ꿪ʼ����
һֱ���� m������ m �ĵ겻������ѡ��Χ�ڣ�ʣ�µĵ��ٽ��Ŵ� 1 ��ʼ����
����һֱ�ظ������ʣ���ļҵ꣬����ȥ�Ǽҵ����·���
���ܸ���ɺɺ����ȥ���Ϊ���ٵĵ����·�ô��*/

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
