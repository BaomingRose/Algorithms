#include<iostream>
using namespace std;

int main()
{
	int result[40000]; //���������������
	int height = 1;  //��������λ
 	int num;  //����׳˵�����
	while(cin>>num)
	{
		result[0] = 1;
		for (int i=1;i<=num;i++)
		{
			int res = 0; //��λ
			for (int j=0;j<height;j++)
			{
	   			int buf = result[j] * i + res; //������
	     			result[j] = buf % 10;  //ȡ��ǰλ
	     			res = buf / 10;   //�����λ
	   		}
	   		while (res)
	   		{
	    			result[height++] = res % 10; //ȡ��ǰλ
				res /= 10;   //�����λ 
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
