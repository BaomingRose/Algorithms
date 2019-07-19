#include<iostream>
using namespace std;

int binarySearch(int* a, int left, int right, int find)
{
	int mid;
	
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(a[mid] < find)
			left = mid + 1;
		else if(a[mid] > find)
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}

int main()
{
	int a[] = { 1, 3, 4, 5, 6, 7, 8};
	cout << binarySearch(a, 0, 6, 0) + 1 << endl;
}
