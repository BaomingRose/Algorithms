/*������ʯ�ӣ��������⣬���Բ�ͬ����Ϸ��ʼ������������ȡʯ�ӡ�
��Ϸ�涨��ÿ�������ֲ�ͬ��ȡ����һ�ǿ����������һ����ȡ��������ʯ�ӣ�
���ǿ�����������ͬʱȡ����ͬ������ʯ�ӡ�����ʯ��ȫ��ȡ����Ϊʤ�ߡ�
���ڸ�����ʼ������ʯ�ӵ���Ŀ������ֵ�����ȡ������˫������ȡ��õĲ��ԣ����������ʤ�߻��ǰ��ߣ�
���Ҳ�������У����������ǰ��ߣ���Ϊ0����֮�����1*/

#include<iostream>
using namespace std;
#include<cmath>

const double ep1 = (sqrt(5.0) - 1.0) / 2.0;
const double ep2 = (sqrt(5.0) + 1.0) / 2.0;

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) && (m || n)) {
        if(m > n) {
            int tmp;
            tmp = m, m = n, n = tmp;
        }
        int id = m * ep1;
        int tmp1 = ep2 * id, tmp2 = tmp1 + id;
        int tmp3 = ep2 * (id + 1), tmp4 = tmp3 + id + 1;
        if(tmp1 == m && tmp2 == n)  cout << "0" << endl;
        else if(tmp3 == m && tmp4 == n) cout << "0" << endl;
        else    cout << "1" << endl;
    }
    return 0;
}
