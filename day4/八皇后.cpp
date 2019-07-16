#include<iostream>
using namespace std;
#include<cmath> 

int row[8] = { 0 };

void eightQueen(int now)	//now ��ʾ���ڷŻʺ������ �����ڷŵ�now���ʺ� 
{
	if(now == 8) 
	{
		for(int col = 0; col < 8; ++col)
		{
			printf("%d ", row[col]);
		}
		printf("\n");
		return ;
	}
	int col, rowed;
	for(col = 0; col < 8; ++col)		//col��ʾÿ�е���λ�� 
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
			eightQueen(now + 1);
		}
	}
}

int main()
{
	eightQueen(0);
	return 0;
}
