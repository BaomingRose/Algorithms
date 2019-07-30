/*��Ŀ����
���� f(x).
�� x < 10 f(x) = x.
��x >= 10 f(x) = a0 * f(x-1) + a1 * f(x-2) + a2 * f(x-3) + ���� + a9 * f(x-10);
 ai(0<=i<=9) ֻ��Ϊ 0 �� 1 .
��֪ a0 ~ a9 ������������ k �� m ���� f(k)%m.
����
��������������������
��ÿ������£��������С�
�ڵ�һ����������������k��m��(k < 2 * 10 ^ 9 m < 10 ^ 5)
�ڵڶ����У���10����������a0 ~ a9
���
ÿ��������һ������� f(k) % m 
��������
10 9999
1 1 1 1 1 1 1 1 1 1
20 500
1 0 1 0 1 0 1 0 1 0
�������
45
104
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 10;
int k, m;
struct Matrix {		//�ýṹ���������
    long long int mat[N][N];	//ֱ����long long int ������
}matrix;
void init() {
    for (int i = 0; i < N; ++i)
    	scanf("%lld", &matrix.mat[0][i]);
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j + 1)
            	matrix.mat[i][j] = 1;
            else
            	matrix.mat[i][j] = 0;
        }
    }
}
Matrix operator * (Matrix a, Matrix b) {		//����˺�
    Matrix c;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            c.mat[i][j] = 0;//��ʼ��ֵΪ0
            for (int k = 0; k < N; ++k)
            	c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            c.mat[i][j] %= m;//�ǵ�ȡģ�������ը��
        }
    }
    return c;
}
Matrix Pow (int n) {		//��������ݺ���
    Matrix t;
    if (n == 1)
    	return matrix;
    if (n & 1)
    	return matrix*Pow(n-1);
    else {
        Matrix temp = Pow(n >> 1);
        return temp * temp;
    }
}
int main() {
    //freopen("de.txt", "r", stdin);
    while (~scanf("%d%d", &k, &m)) {
        init();
        if (k < 10) {
            printf("%lld\n", matrix.mat[0][k] % m);
            continue;
        }
        Matrix temp = Pow(k - 9);
        long long int ans = 0;
        for (int i = 0; i < N; ++i) {
            ans += temp.mat[0][i] * (N - i - 1);
            ans %= m;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
