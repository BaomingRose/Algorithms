/*
喵星发布了一种新型钞票，这种钞票有正有负，给定一个长度为k的钞票序列，
然后红红通过数钞票来获得钞票，但是红红有一个怪癖，他仅仅只是拥有连续的记忆，
意思就是他只能连续计数，但是红红想要获得尽可能多的钱，但是红红做不到。
举个例子，给定钞票序列是{-2 11 -4 13 -5 -2} 而红红去数的最大子序列就是就是{11 -4 13 } 
所以红红能够获得最多钱为20。
现在请你来帮助红红早日发家致富。

输入
每一个样例包含一组数据。每一组数据包含两行。
第一行包含一个正整数k(<=10000)。
第二行包含K个数，每一个数中间用空格隔开。

输出
对于每一个样例输出，都输出一行。
这一行的第一个数字就是最大的和
后面两个数 就是这个钞票序列的起始的数i和 终止的数 
这些数字必须以空格相隔开，并且在每一行的末尾没有额外的空格。
另外 可能这个最大的钞票序列往往并不是唯一的，所以只需要输出包含最小的起始坐标或者终止坐标。
注意 如果所有的数全部都是负数，那么其的最大钞票和为0，且你应该输出的是从这整个序列第一个数到最后一个数。

样例输入
10
-10 1 2 3 4 -5 -23 3 7 -21
样例输出
10 1 4
 
其实这道题也算是一道特别简单的题目，还是动态规划里面最基础的问题，但是总是容易去弄混。
记得自己当时的问题就在于 这里每一次相加的和，如何保证后面加了负数之后，再次加上一个正数不被影响呢，
下面的注释里面有写，
因为题目中限制了，如果这道题有多个答案，比如说 前面与后面相加为零，但是后面的那个正数正好作为最后的正确答案的话
比如 1 2 -3 8
	1 2 -3 正好相加为0  但是题目中要求的 序列 1 2 -3 8 作为最后的结果序列。
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<cmath>

using namespace std;



int main()
{
	std::ios::sync_with_stdio(false);
	int m;
    cin >> m;
    int num[m + 5];
    
    for (int i = 0; i < m; i++) {
        cin >> num[i];
    }
    
    int left = 0;
    int tmpleft = 0;
    int right = m - 1;
    int tmp = 0;
    int Max = -1;

    for (int i = 0; i < m; i ++) {
        tmp += num[i];
        if (tmp < 0) {
            tmp = 0;
            tmpleft = i + 1;
        }
        else if (tmp > Max) {
            Max = tmp;
            right = i;
            left = tmpleft;
        }
    }
    
    if (Max >= 0) cout << Max << " " << num[left] << " " << num[right] << endl;
    else cout << 0 << " " << num[0] << " " << num[m - 1] << endl;

    return 0;
}
