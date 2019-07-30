/*斐波那契数列的定义如下:
 F(0) = 0
F(1) = 1
F(n) = F(n - 1) + F(n - 2) (n >= 2)
 (1 1 2 3 5 8 13 21 34 55 89 144 233 377 ...)
给出n，求F(n)，由于结果很大，输出F(n) % 1000000009的结果即可.
输入
输入1个数n(1 <= n <= 10^18).
输出
输出F(n) % 1000000009的结果.
样例输入
11
样例输出
89
*/

/*构造矩阵 
【f(n-1),f(n-2)】*A=【f(n),f(n-1)】;
所以
【f(2),f(1)】*A^n-2=【f(n),f(n-1)】;
因为，f(n)=f(n-1)+f(n-2),f(n-1)=0*f(n-1)+1*f(n-2) 
所以矩阵A应该是
1 1
1 0*/

#include <iostream>
#include<cstdio>
using namespace std;

#define LL long long

const LL INF = 1000000009;
struct Node{
   LL a[2][2];
}t;
Node mult(Node a, Node b) {      //矩阵相乘
    Node c = {0};
     for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
          for(int k = 0; k < 2; k++) {
               c.a[i][j] += a.a[i][k] * b.a[k][j];
               c.a[i][j] %= INF;
          }
     return c;


}
Node pow(LL n) {       //快速幂
    Node pt = t;
    if(n < 0)
        return pt;
    while(n) {
        if(n & 1)
          pt = mult(pt, t);
        t = mult(t, t);
        n >>= 1;
    }
    return pt;
}
int main() {
	LL n;
	scanf("%lld", &n);
	t.a[0][0] = 1;
	t.a[0][1] = 1;
	t.a[1][0] = 1;
	t.a[1][1] = 0;
	Node ans = pow(n-2);
	printf("%lld\n", ans.a[0][0]);
	return 0;
}
