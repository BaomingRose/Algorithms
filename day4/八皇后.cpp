#include<iostream>
using namespace std;
#include<cmath> 

int row[8] = { 0 };

void eightQueen(int now)	//now 表示正在放皇后的行数 即正在放第now个皇后 
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
	for(col = 0; col < 8; ++col)		//col表示每行的列位置 
	{
		for(rowed = 0; rowed < now; ++rowed)		//rowed 表示已经放好的皇后的行数 
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
