/*迭代法求平方根
平方根迭代公式：x1 = 1/2*(x0+a/x0)
1.设置一个初值x0作为a的平方根，在程序中取a/2作为a的初值；利用迭代公式求出一个x1.此值与真正的a的平方根值相比会有很大的误差
2.把新求得的x1带入x0，用这个新的x0在去求出一个新的x1
3.利用迭代公式在求出一个新的x1的值，即用新的x0求出一个新的平方根x1，此值将更加趋近于真正的平方根值
4.比较前后两次求得的平方根值x0和x1，如果他们的差值小于指定的值，即达到要求的精度，
  则认为x1就是a的平方根值，去执行步骤5；否则执行步骤2，即循环进行迭代
5.输出结果
*/ 

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main() {
	double a, x0, x1;
	cout << "Input a:" << endl;
	cin >> a;
	if(a < 0) {
		cout << "Error!" << endl;
	} else {
		x0 = a / 2;
		x1 = (x0 + a / x0) / 2;
		do {
			x0 = x1;
			x1 = (x0 + a / x0) / 2;
		} while(fabs(x0 - x1) >= 1e-6);
	}
	cout << "Result:" << endl;
	//%g用来输出实数，它根据数值的大小，自动选f格式或e格式（选择输出时占宽度较小的一种），
	//且不输出无意义的0。即%g是根据结果自动选择科学记数法还是一般的小数记数法
	printf("sqrt(%g)=%g\n", a, x1);
	return 0;
} 
