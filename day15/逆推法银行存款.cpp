/*ĸ��Ϊ����Sun��4���ѧѧ��׼����һ�ʴ���ʽ��������ȡ���涨СSunÿ���µ�ȡ��һ���µ������
���ڼ������е�����ϢΪ1.71%�����д���򣬼���ĸ��������Ҫ�������Ǯ��
���Ʒ�������Ǯ��ȡǮ�Ĺ���*/
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
		printf("%2d����ĩ�������ƣ�%.2f\n", i, corpus[i]);
	}
	return 0;
}
