/*现在有一些写着数字的卡片，我们定义一个规则：
两张数字相同的卡片是 OK 的，
三张连续数字的卡片是 OK 的，
给你一堆卡片，请你找出尽可能多的 OK 数，卡片不可以重复利用。*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 1000005
int a[maxn];
 
int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
	int n;
	while(scanf("%d", &n) && n){
		int x, ans = 0;
		memset(a, 0, sizeof(a));
		for(int i = 0; i < n; i++){
			scanf("%d", &x);
			a[x]++;
		}
		for(int i = 1; i <= n; i++){
			if(i <= 2){
				ans += a[i] / 2;
				a[i] %= 2;
			}else{
				if(a[i] && a[i-1] && a[i-2]){
					ans++;
					a[i]--;
					a[i-1]--;
					a[i-2]--;
				}
				ans += a[i] / 2;
				a[i] %= 2;
			}
		}
		printf("%d\n", ans);
	}
}

