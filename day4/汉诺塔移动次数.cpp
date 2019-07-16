#include<iostream>
using namespace std;

int hanio(int n)
{
	if(n == 1)
		return 1;
	else
		return  2 * hanio(n - 1) + 1;
}

//最下层的为移动 1次， 向上依次*2 
int hanoii(int n, int x)
{
	if(x == n)
		return 1;
	return 2 * hanoii(n, x + 1);
} 

int main()
{
	int n, x;
	while(cin >> n >> x)
		cout << hanio(n) << " " << hanoii(n, x) << endl;;

	
	return 0;
}
