/*Сѧ�������N�������ų�һ�ţ����������α��Ϊ123....N.
ÿ�θ���2������a b(a <= b)��Ƥ�ĺ����ӵ�кܶ��ֲ�ͬ��ɫ������
������������a��ʼ������b���θ�ÿ������Ϳһ����ɫ��
����N���Ժ����Ѿ������˵�I�������Ѿ�Ϳ��������ɫ�ˣ�
���ܰ������ÿ������Ϳ��������ɫ��*/

#include<iostream>
using namespace std;
#include<cstring> 

const int maxn = 100005;
int ax[maxn];

void change(int a, int b) {
	for(int i = a; i <= b; ++i) {
		++ax[i];
	}
}

int main() {
	int num;
	int a, b;
	int tmp;
	while(cin >> num && num) {
		memset(ax, 0, sizeof(ax));
		tmp = num;
		while(num--) {
			cin >> a >> b;
			change(a, b);
		}
		for(int i = 1; i <= tmp; ++i) {
			if(i == 1)
				cout << ax[i];
			else
				cout << " " << ax[i];
		}
		cout << endl;
	}
	return 0;
}

/*�������� 
3
1 1
2 2
3 3
3
1 1
1 2
1 3
0*/
