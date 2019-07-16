#include<iostream>
using namespace std;

int Fab(int a)
{
	if(a == 1 || a == 2)
	{
		return 1;
	}
	return Fab(a - 1) + Fab(a - 2);
}

int main()
{
	cout << Fab(7) << endl;
}
