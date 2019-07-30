/*쳲��������еĶ�������:
 F(0) = 0
F(1) = 1
F(n) = F(n - 1) + F(n - 2) (n >= 2)
 (1 1 2 3 5 8 13 21 34 55 89 144 233 377 ...)
����n����F(n)�����ڽ���ܴ����F(n) % 1000000009�Ľ������.
����
����1����n(1 <= n <= 10^18).
���
���F(n) % 1000000009�Ľ��.
��������
11
�������
89
*/

/*������� 
��f(n-1),f(n-2)��*A=��f(n),f(n-1)��;
����
��f(2),f(1)��*A^n-2=��f(n),f(n-1)��;
��Ϊ��f(n)=f(n-1)+f(n-2),f(n-1)=0*f(n-1)+1*f(n-2) 
���Ծ���AӦ����
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
Node mult(Node a, Node b) {      //�������
    Node c = {0};
     for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
          for(int k = 0; k < 2; k++) {
               c.a[i][j] += a.a[i][k] * b.a[k][j];
               c.a[i][j] %= INF;
          }
     return c;


}
Node pow(LL n) {       //������
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
