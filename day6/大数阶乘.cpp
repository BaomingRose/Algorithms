#include<iostream>
using namespace std;

int main()
{
	int result[40000]; //保存结算结果的数组
	int height = 1;  //结果的最高位
 	int num;  //计算阶乘的数字
	while(cin>>num)
	{
		result[0] = 1;
		for (int i=1;i<=num;i++)
		{
			int res = 0; //进位
			for (int j=0;j<height;j++)
			{
	   			int buf = result[j] * i + res; //计算结果
	     			result[j] = buf % 10;  //取当前位
	     			res = buf / 10;   //计算进位
	   		}
	   		while (res)
	   		{
	    			result[height++] = res % 10; //取当前位
				res /= 10;   //计算进位 
			}
	  	}
		
		for (int k=height-1;k>=0;k--)
		{
	   		cout<<result[k];
		}
		cout<<endl;
		for(int i = 0; i < 4000; ++i)
		{
			result[i] = 0;
		}
	}
 	return 0;
}
