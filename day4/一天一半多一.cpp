#include<iostream>
using namespace std;

//ตÝน้

int n, m, t;
int Fun(int x)
{
	if(x == n)
		return m;
	return 2 * (Fun(x + 1) + 1);
}




#if 0
int main()
{
    int n, m, t;
    int sum = 0;
    while(cin >> n >> m >> t)
    {
    	sum = m;
        for(int i = 1; i < n; ++i)
        {
            sum = (sum + 1) * 2;
        }
        cout << sum * t << endl;
 
    }
    return 0;
    
}


#endif
