/*�ж����Ʒ������������ĳһ��ȡ��������Ʒ���涨ÿ������ȡһ����
���߲��ޣ����ȡ���߻�ʤ��
�����������
��һ�� ���� n ��������n����Ʒ
������n���� ����ÿ����Ʒ������*/

#include<iostream>
using namespace std;

int main() {
    int num, m;
    int res = 0;
    while(cin >> num) {
        for(int i = 0; i < num; ++i) {
            cin >> m;
            res ^= m;
        }
        if(res == 0) {
            cout << "second" << endl;
        } else {
            cout << "first" << endl;
        }
    }
    return 0;
}
