/*һ��ʯ�ӣ�һ��ȡһ����m�������ȡ���߻�ʤ 
�����������Ȱ���һ��������C(C<=100)����ʾ��C��������ݡ� 
ÿ���������ռһ�У�������������n��m��1<=nm<=1000����n��m�ĺ������Ŀ������
������ߵ�����Ӯ���������first���������������second����ÿ��ʵ�������ռһ�С�*/


#include<iostream>
using namespace std;

int main() {
    int num; 
    cin >> num;
    int m, n;
    while(num--) {
        cin >> m >> n;
        if(m % (n + 1) == 0)
            cout << "second" << endl;
        else
            cout << "first" << endl;
    }
    return 0;
}
