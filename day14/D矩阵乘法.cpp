/*题目描述
函数 f(x).
若 x < 10 f(x) = x.
若x >= 10 f(x) = a0 * f(x-1) + a1 * f(x-2) + a2 * f(x-3) + …… + a9 * f(x-10);
 ai(0<=i<=9) 只能为 0 或 1 .
已知 a0 ~ a9 和两个正整数 k 与 m 计算 f(k)%m.
输入
问题包含多个测试用例。
在每种情况下，都有两行。
在第一行中有两个正整数k和m。(k < 2 * 10 ^ 9 m < 10 ^ 5)
在第二行中，有10个整数代表a0 ~ a9
输出
每个样例在一行里输出 f(k) % m 
样例输入
10 9999
1 1 1 1 1 1 1 1 1 1
20 500
1 0 1 0 1 0 1 0 1 0
样例输出
45
104
*/

#include <bits/stdc++.h>

using namespace std;
const int N = 10;
int k, m;
struct Matrix {		//用结构体来存矩阵
    long long int mat[N][N];	//直接上long long int 别找事
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
Matrix operator * (Matrix a, Matrix b) {		//定义乘号
    Matrix c;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            c.mat[i][j] = 0;//初始化值为0
            for (int k = 0; k < N; ++k)
            	c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            c.mat[i][j] %= m;//记得取模，否则就炸了
        }
    }
    return c;
}
Matrix Pow (int n) {		//定义快速幂函数
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
