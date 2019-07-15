/*���Ƕ�֪���������������Ϣ�ǰ������ȼ�����ġ�
���Ƕ������¹���
    1. ÿ����Ϣ�������������ԣ��ֱ������ݺ����ȼ���
    2. ����һ���ռ䣬���Դ������е���Ϣ��
    3. ������һ�� ��PUSH�� ָ��������� һ������(�ַ���)�� ��һ�����ȼ�(������Խ��Խ����)��
    4. ������һ�� ��POP�� ָ����ռ�������Ϣ�����������Ϣ�����ݣ��������"NULL!"��
    5. ���������Ϣ�����ȼ�һ������Խ�����������Խ���ȡ�*/

#include<iostream>
using namespace std;
#include<queue>
#include<string>

string op, data;
int vip;

struct node
{
	string data;
	int vip;
} temp;

bool operator < (node a, node b)
{
	if(a.vip < b.vip)
	{
		return true;
	}else
	{
		return false;
		
	}
}

int main()
{
	priority_queue<node> q;
	while(cin >> op)
	{
		if(op == "PUSH")
		{
			cin >> data >> vip;
			temp.data = data;
			temp.vip = vip;
			q.push(temp);
		}
		else
		{
			if(q.empty())
				cout << "NULL!" << endl;
			else
			{
				temp = q.top();
				
				cout << temp.data << endl;
				q.pop();
			}
		}
	}
	
	return 0;
}
