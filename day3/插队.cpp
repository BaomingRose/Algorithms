/*Сѩ��С�ڳ�ȥ�Է��������������˲�ӣ���ȻҲ�����뿪 
ÿ���������˲�ӵ�ʱ��Сѩ�ͻ���С��ȥ��һ��ǰ���˵��Ŷ��벢������
���ܰ��С��ô��*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
  int t, n, m;
  vector <int> a(0);
  char c[7];
  cin >> t >> n;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &m);
    a.insert(a.begin() + i, m);
  }
  int i, j;
  while (t--)
  {
    scanf("%s", c);
    if (c[0] == 'l')
	{
      scanf("%d", &i);
      a.erase(a.begin()+i-1);
    }
    else
	{
      scanf("%d %d", &i, &j);
      a.insert(a.begin() + i-1, j);
      for(i = 0; i < a.size()-1; i++) cout << a[i] << " " ;
      cout << a[a.size()-1] << endl;
    }
  }
  return 0;
}


