/*���������֣� ��������ֻ���ö���Ԫ�س����ж��ܲ���������
���Ƕ�β���ܽ��ˣ����Ժ����������������������ǡ�
���ǿ���������ж������������ͬ���������𡣱����������ǣ� 
1 2 3 2 1 �� 1 3 2 2 1���ó����׵�1����������
���ǿ���������+2ʣ�����������е�Ԫ���� 2 3 2 1�� 3 2 2 1�� 
�ڶ���2��3�޷������Ǿ��ӵ���һ�ӵ����ǣ�����Ǹ��д�ֹ۵��ˣ�
����һ����Ϊ��ʱ�޷��������������
����Ҫ���� STL����
queue ���� ����Ԫ�� q.front(); */

#include<iostream>
using namespace std;
#include<queue>

int main()
{
	queue<int> q1;
	queue<int> q2;
	int num;
	int b;	//����Ԫ�� 
	int count;
	while(cin >> num)
	{
		while(q2.empty() == 0)
			q2.pop();			//q2Ҫ��� 
	
		for(int i = 0; i < num; ++i)
		{
			cin >> b;
			q1.push(b);
		}
		for(int i = 0; i < num; ++i)
		{
			cin >> b;
			q2.push(b);
		}  
		while(q1.size() != 0)
		{
			if(q1.front() == q2.front())
			{
				count += 2;
				q1.pop();
				q2.pop();
			}
			else
			{
				q1.pop();
			}
		}
		cout << count << endl;
		count = 0;
	}
}
