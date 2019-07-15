/*小雪和小磊出去吃饭，但是老是有人插队，当然也有人离开 
每当发现有人插队的时候，小雪就会让小磊去看一下前面人的排队码并报给她
你能帮帮小磊么？*/

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


