/*判断两个数是否相等，01.00 1.0 是相等的， 0001 1 是相等的, 0.01 0.0100*/

#include<iostream>
using namespace std;
#include<string>

void cutString(string& a)
{	
	if (a[a.size() - 1] == '0')
	{
		for (int i = 0; i < a.size(); ++i)
		{
			if (a[i] == '.')
			{
				for (int j = a.size() -1; a[j] == '0'; --j)
				{
					a.pop_back();
				}
				if (a[a.size() - 1] == '.')
				{
					a.pop_back();
				}
			}
		}
	}
	if (a[0] == '0')
	{
		for (int i = 0; i < a.size(); ++i)
		{
			if (a[i] != '0')
			{
				a.erase(0, i);
				break;
			}
		}
	}
}



int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		cutString(a);
		cutString(b);
		if (a == b)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
