/*��Ŀ����
�����������˳Լ���������n�������ÿһ�����������Ϊc(<=1e3)���ͼ�ֵΪv(v <= 1e3)
���������ؾͼ�һ��������������ΪS�����ʺ����Գ�Ϊ��ʵĿ��Ա��
����
����ĵ�һ��ΪT�� ��ʾ���Ҫ��T��ɡ��
ÿһ��������������ɡ�
��һ�а�����������n s���ֱ��ʾ�����ͱ����������ڶ��а���n����������ʾÿһ������ļ�ֵ��
�����а���n����������ʾÿһ�����������
���
����ÿһ�����ݣ���������Զ�ʡ�
��������
1
10 10
1 3 5 7 9 11 13 15 17 19
19 17 15 13 11 9 7 5 3 1
�������
51
*/

#include<iostream>
using namespace std;
#include<cmath>
#include<cstring>

int data[12881];
int weight[3403];
int value[3403];

int main() {
	int num;
	cin >> num;
	int n, size;	//size �������� 	n ��Ʒ���� 
	int i, j;
	while(num--) { 
		memset(data, 0, sizeof(data));
		cin >> n >> size;
		for(i = 1; i <= n; ++i) {
			cin >> value[i];
		}
		for(i = 1; i <= n; ++i) {
			cin >> weight[i];
		}
		
		for (i = 1; i <= n; i++) {
			for (j = size; j >= weight[i] ; j--) {
				data[j] = max(data[j], data[j - weight[i]] + value[i]);
			}
		}
		cout << data[size] << endl;
	}
	return 0;
	
}
