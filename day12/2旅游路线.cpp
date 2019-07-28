/*��Ŀ����
�����ٺ����ȥ��������,�������߻�����С��·��.����Ѿ��о����˰��Լ����������͵�������·��.
��Щ·�߰�����ʼ����յ���һ������T(1<=T<=2500)������,����ر��Ϊ1��T.
���������յ����ÿ������������˫���·�����������������س���.
ÿ����·��һ��ͨ�����ã������ͷ�,��·�ѵȵȣ��� 
����һ����ͼ,����m(1<=m<=6200)��ֱ������2������ĵ�·��ÿ����·�ɵ�·�����Rs,�յ�Re(1<=Rs<=T;1<=Re<=T),
�ͻ���(1<=Ci<=1000)���.�����ʼ�ĳ���Ts(1<=Ts<=T)���յ�ĳ���Te(1<=Te<=T)��С���ܷ���. 
����
��һ��: 4���ɿո����������: T m Ts Te 
��2����C+1��: ��i+1��������i����·.��3���ɿո����������: Rs Re��Ci 
���
һ��������������ʾ��Ts��Te����С�ܷ���.���ݱ�֤���ٴ���һ����·. 
��������
7 11 5 4 
2 4 2 
1 4 3 
7 2 2 
3 4 3 
5 7 5 
7 3 3 
6 1 1 
6 3 4 
2 4 3 
5 6 3 
7 2 1 
�������
7
��ʾ
5->6->1->4(3+1+3)
*/

/*����������������·��SPFAһ�¾ͺ��ˣ���Ȼ���кܶ�취��*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int T, C, Te, Ts, head[63000], tot, dist[63000];
bool passby[63000];
queue<int> q;

struct Edge
{
    int to, dist, next;
}edge[63000];

void add(int ff,int tt,int dd)
{
    edge[++tot].to = tt;
    edge[tot].dist = dd;
    edge[tot].next = head[ff];
    head[ff] = tot;
}

void spfa(int s)
{
    dist[s] = 0;
    passby[s] = 1;
    q.push(s);
    for(; !q.empty(); ) {
        int x = q.front(); 
		q.pop(); 
		passby[x] = 0;
        for(int i = head[x]; i; i = edge[i].next) {
            Edge e = edge[i];
            if(dist[e.to] > dist[x] + e.dist) {
                dist[e.to] = dist[x] + e.dist;
                if(!passby[e.to]) {
                    passby[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
    }
}
int main() {
    cin >> T >> C >> Ts >> Te;
    for(int i = 1; i <= T; i++)	dist[i] = 0x7fffffff;
    for(int i = 1; i <= C; i++) {
        int Rs, Re, Ci;
        cin >> Rs >> Re >> Ci;
        add(Rs, Re, Ci);
		add(Re, Rs, Ci);
    }
    spfa(Ts);
    cout << dist[Te];
    return 0;
}


