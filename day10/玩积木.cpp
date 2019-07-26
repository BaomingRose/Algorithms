
/*考虑到返回值的范围要使用long long int */ 
#include<iostream>
using namespace std;

long long int fun(int n) {
    long long int last1 = 2, last2 = 1, cur;
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    for(int i = 3; i <= n; ++i) {
        cur = last1 + last2;
        last2 = last1;
        last1 = cur;
    }
    return cur;
}

int main()
{
	int n;
	while(cin >> n) {
	    cout << fun(n) << endl;
	}
	return 0;
}
