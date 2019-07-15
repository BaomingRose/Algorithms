/*队列消消乐， 即消消乐只能拿队首元素出来判断能不能消除，
但是队尾不能进人，所以红红决定拿两个队列来存星星。
星星可以消灭的判断依据是序号相同，即可消灭。比如两队星星， 
1 2 3 2 1 和 1 3 2 2 1，拿出队首的1，可以消灭，
于是可消灭星星+2剩余两个队列中的元素是 2 3 2 1和 3 2 2 1， 
第二次2和3无法消灭，那就扔掉第一队的星星，红红是个有大局观的人，
当第一队列为空时无法继续消灭；则结束
本题要求用 STL库做
queue 队列 队首元素 q.front(); */

#include<iostream>
using namespace std;
#include<queue>

int main()
{
	queue<int> q1;
	queue<int> q2;
	int num;
	int b;	//队列元素 
	int count;
	while(cin >> num)
	{
		while(q2.empty() == 0)
			q2.pop();			//q2要清空 
	
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
