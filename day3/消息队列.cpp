/*我们都知道，计算机储存消息是按照优先级输出的。
我们定义以下规则：
    1. 每个消息，都有两个属性，分别是数据和优先级。
    2. 存在一个空间，可以储存已有的消息。
    3. 当遇到一个 “PUSH” 指令，后面会跟着 一个数据(字符串)， 和一个优先级(整数，越大越优先)。
    4. 当遇到一个 “POP” 指令，若空间中有信息，则输出该信息的数据，否则输出"NULL!"。
    5. 如果两个消息，优先级一样，则越早输入的数据越优先。*/

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
