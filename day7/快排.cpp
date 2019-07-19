/*给出n个无序的整数，请输出其中第k大的数。(请应用分治(快排)思想)*/

#include<iostream>
using namespace std;

int arr[10000000] = { 0 };

void quickSort(int *a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int i = left;
	int j = right;
	int key = a[left];
	while (i < j)
	{
		while (i < j && key >= a[j])
		{	
			--j;		
		}
		a[i] = a[j];
		while (i < j && key <= a[i])
		{
			++i;
		}
		a[j] = a[i];
	}
	a[i] = key;
	quickSort(a, left, i - 1);
	quickSort(a, i + 1, right);
}

int main()
{
	int num, p;
	while(cin >> num >> p)
	{
		for(int i = 0; i < num; ++i)
		{
			cin >> arr[i];
		}
		quickSort(arr, 0, num -1);
		cout << arr[p - 1]<< endl;
		for(int i = 0; i < num; ++i)
		{
			arr[i] = 0;
		}
	}
	return 0;
}
