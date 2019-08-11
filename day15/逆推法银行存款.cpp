/*母亲为儿子Sun的4年大学学费准备了一笔存款，方式是整存零取，规定小Sun每月月底取下一个月的生活费
现在假设银行的年利息为1.71%，请编写程序，计算母亲最少需要存入多少钱？
逆推法分析存钱和取钱的过程*/
#include<iostream>
#include<cstdio>

using namespace std;
const int FETCH = 1000;
const double RATE = 0.0171;

int main() {
	double corpus[49];
	int i;
	corpus[48] = (double)FETCH;
	for(i = 47; i > 0; --i) {
		corpus[i] = (corpus[i + 1] + FETCH) / (1 + RATE / 12);
	}
	for(i = 48; i > 0; --i) {
		printf("%2d月月末本利共计：%.2f\n", i, corpus[i]);
	}
	return 0;
}
