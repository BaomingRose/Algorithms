/*�����������
ÿ��Ϊһ����֪���ж೤���ַ��� s ��Ȼ����һ���ַ���ʾ c Ҫ��ѯ����ĸ���м��ÿո������
��֤�ַ�����ֻ��Сд��ĸ��
���
���Ҫ��ѯ����ĸ���ַ����г��ֹ���λ�ã��ַ����±��һ��ʼ��
���Ҫ��ѯ����ĸ�����ַ����У���� NO*/


#include<iostream>
using namespace std;
#include<string> 

int main()
{
	string str;
	char p;
	int flag = 1;
	while(cin >> str)
	{
		cin >> p;
		for(int i = 0; i < str.size(); ++i)
		{
			
			if(str[i] == p)
			{
				flag = 0;
				cout << i + 1 << " " ;
			}	
						
		}
		if(flag)
		{
			cout << "NO" ;
		}	
		cout << endl;
		flag = 1;
	}
	return 0;
}
