/*ŷ�޹ھ��������ճ̰���
�����׶β���ѭ���ƣ� ����n�Ӳμӣ�������n-1�죬Ҫ��ÿ��ÿ��ֻ�ܽ���һ�����������Ҳ����ֿ�
��������Ҫ���ű����ճ̣�����ÿ����ӵĶ���
�㷨˼�룺���ݷ����㷨˼·�������в�������ֳ����룬��n�ӵı����ճ̱����ͨ��n/2���ӵı����ճ�������
Ȼ��������һ��Ϊ���ķ����Բ����ӽ��л��֣�ֱ��ֻʣ���������ʱΪֹ*/ 

#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 64;
int a[MAXN + 1][MAXN + 1] = { 0 };

void gamecal(int k, int n) {		//������k��ʼ��n����ӵ��ճ� 
	int i, j;
	if(n == 2) {
		a[k][1] = k;	//������ӱ��
		a[k][2] = k + 1;	//������ӱ�� 
		a[k + 1][1] = k + 1;	//������ӱ�� 
		a[k + 1][2] = k; 		//������ӱ�� 
	} else {
		gamecal(k, n / 2);
		gamecal(k + n / 2, n / 2);
		for(i = k; i < k + n / 2; ++i) {		//������½� 
			for(j = n / 2 + 1; j <= n; ++j) {
				a[i][j] = a[i + n / 2][j - n / 2];
			}
		}
		for(i = k + n / 2; i < k + n; ++i) {		//������½� 
			for(j = n / 2 + 1; j <= n; ++j) {
				a[i][j] = a[i - n / 2][j - n / 2];
			}
		}
	}
}

int main() {
	int m, i, j;
	cout << "�����������";
	cin >> m;
	j = 2;
	for(i = 2; i < 8; ++i) {
		j *= 2;
		if(j == m) break;
	}
	if(i >= 8) {
		cout << "�������������Ϊ2���������ݣ����Ҳ�����64��" << endl;
		return 0;
	}
	gamecal(1, m);
	cout << endl << "��� " ;
	for(i = 2; i <= m; ++i) {
		printf("%2d�� ", i - 1);
	}
	cout << endl;
	for(i = 1; i <= m; ++i) {
		for(j = 1; j <= m; ++j) {
			printf("%4d ", a[i][j]);
		}
		cout << endl;
	}
	return 0;
}

