#include<iostream>
using namespace std;
#include<cmath> 

int row[9] = { 0 };
int flag = 1; 

void nineQueen(int now)	//now ��ʾ���ڷŻʺ������ �����ڷŵ�now���ʺ� 
{
	if(now == 9 && flag == 1) 
	{
		for(int col = 0; col < 9; ++col)
		{
			if (col)
				cout << " ";
			cout << row[col] + 1;
		}
		cout << endl;
		flag = 0;
		return ;
	}
	int col, rowed;
	for(col = 0; col < 9; ++col)		//col��ʾÿ�е���λ�� 
	{
		for(rowed = 0; rowed < now; ++rowed)		//rowed ��ʾ�Ѿ��źõĻʺ������ 
		{
			if(col == row[rowed] || abs(now - rowed) == abs(col - row[rowed]))
			{
				break;
			}
		}
		if(rowed == now)
		{
			row[now] = col;
			nineQueen(now + 1);
		}
	}
}

int main()
{
	nineQueen(0);
	return 0;
}
