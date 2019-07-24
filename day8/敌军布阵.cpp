/*C��������ͷA�����ʱ�����ڽ��о�����ϰ��
����C�����ͷ��Derek��������Tidy�ֿ�ʼæ���ˡ�
A���ں�������ֱ�߲�����N������Ӫ��Derek��Tidy���������Ҫ������Щ����Ӫ�صĻ�����
���ڲ�ȡ��ĳ���Ƚ��ļ���ֶΣ�����ÿ������Ӫ�ص�����C�������յ�һ�����ÿ������Ӫ�ص��������п��ܷ����䶯��
�������ӻ�����������ֵ���Щ���Ӳ���C���ļ��ӡ� 
�����鱨��Ҫ�о����˾�����ϰʲôս������TidyҪ��ʱ��Derek�㱨ĳһ�������Ĺ���Ӫ��һ���ж�����
����Derek��:��Tidy���ϻ㱨��3��Ӫ�ص���10��Ӫ�ع��ж�����!��Tidy��Ҫ���Ͽ�ʼ������һ�ε����������㱨��
���б�Ӫ�ص����������䶯����Derekÿ��ѯ�ʵĶζ���һ��������Tidy���ò�ÿ�ζ�һ��һ��Ӫ�ص�ȥ����
�ܿ�;�ƣ�����ˣ�Derek��Tidy�ļ����ٶ�Խ��Խ����:"��������У������ô�����ҳ�������!��
Tidy�룺�����Լ������㿴���������һ�����˵Ĺ���!�Һ޲����㳴��������!������֮�£�
Tidyֻ�ô�绰������ר��Windbreaker���Windbreaker˵���������У�����ƽʱ�����acm��Ϳ�����㷨�飬
���ڳ�������˰�!��Tidy˵��"��֪���ˡ�����"��Windbreaker�Ѿ��ҵ��绰�ˡ�Tidy�ܿ��գ�
��ô������Ļ�����ģ������Ķ��ߣ�����д������������������𣿲��������ĳ���Ч�ʲ����ߵĻ���
Tidy���ǻ��ܵ�Derek�������. */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
 
const int maxn = 50005;
int tree[maxn];
int T, N;
 
int lowbit(int x) {
    return x & (-x);
}
 
void update(int x, int num) { 
    for(int i = x; i <= N; i += lowbit(i)) {
        tree[i] += num;
    }
}
 
int getSum(int x) {
    int res = 0;
    for(int i = x; i > 0; i -= lowbit(i)) {
        res += tree[i];
    }
    return res;
}
 
int main()
{
    cin >> T;
    int cnt = 0;
    while(T--) {
        cin >> N;
        memset(tree, 0, sizeof tree);
        int tmp;
        for(int i = 1; i <= N; i++) {
            cin >> tmp;
            update(i, tmp);
        }
        cout << "Case " << ++cnt << ':' << endl;
        string s;
        int x, y;
        while(cin >> s && s[0] != 'E') { 
            if(s[0] == 'Q') {
                cin >> x >> y;
                cout << getSum(y) - getSum(x-1) << endl;
            }
            else if(s[0] == 'A') {
                cin >> x >> y;
                update(x, y);
            }
            else {
                cin >> x >> y;
                update(x, -y);
            }
        }
    }
    return 0;
}

/*����������1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End  */ 
