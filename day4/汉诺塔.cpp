#include<iostream>
using namespace std;

void hanio(int n, char A, char B, char C)
{
	if(n == 1)
	{
		
		cout << " MOVE " << A << " TO " << C << endl;
		
	}
	else
	{
		hanio(n - 1, A, C, B);
		cout << " MOVE " << A << " TO " << C << endl;
		hanio(n - 1, B, A, C);
	}
}

int main()
{
	int n;
	cin >> n;
	hanio(n, 'A', 'B', 'C');
	return 0;
}
