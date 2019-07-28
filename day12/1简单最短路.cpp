/*��Ŀ����
����������ȥСկ���,������Ҫ�ҵ���̵�һ��·,ʱ���������Ҫ��,��������֪������Ҫ����ʱ����ܵ�Сկ
����һ����n ����վ������ѧУ�ſڵĳ�վ���Ϊ1�� Сկվ���Ϊn��֮������һ��m��
�������m��˫��ͨ���Լ�ͨ������Ҫ��ʱ�䡣
����
��һ��N �� M �� 2 <= N <= 1000 1 <= M <= 2000)
�ڶ��е���M+ 1�У���������a �� b �� c ��ʾa վ�㵽b վ����һ��·����Ҫ c min 
���
һ�б�ʾ����Ҫ������ʱ��
��������
5 5
1 2 20
2 3 30
3 4 20
4 5 20
1 5 100
�������
90
*/

#include<iostream>
using namespace std;
#include<cstring>

#define maxn 1005
#define INF 0x3f3f3f3f
int map[maxn][maxn];
int dis[maxn], check[maxn];

int dijkstra(int n) {		//�󶥵�1������n�����·�� 
	memset(check, 0, sizeof(check));
	memset(dis, 0, sizeof(dis));
	for(int i = 1; i <= n; ++i) {
		dis[i] = map[1][i];			//��ʼ��dis��Դ�㼴1��n�ĳ��� 
	}
	check[1] = 1, dis[1] = 0;
	int minx = 0, pos;
	//��ʼ��ѭ����ÿ�����v1��ĳ����������·�� 
	for(int i = 1; i <= n; ++i) {
		minx = INF;
		for(int j = 1; j <= n; ++j) {
			if(!check[j] && minx > dis[j]) {	//j������v1���� 
				minx = dis[j];
				pos = j;
			}
		}
		check[pos] = 1;
		for(int j = 1; j <= n; ++j) {		//���µ�ǰ���·�������� 
			if(!check[j] && dis[j] > minx + map[pos][j]) {		//�޸�dis[j] 
				dis[j] = minx + map[pos][j];
			}
		}
	}
	return dis[n];
}

int main() {
	memset(map, INF, sizeof(map));		//ǿ����Ҫ�ģ��ֽ�����Ȩֵ������� 
	int N, M;
	cin >> N >> M;
	int a, b, c;
	for(int i = 0; i < M; ++i) {
		cin >> a >> b >> c;
		map[a][b] = map[b][a] = c;
	}
	cout << dijkstra(N) << endl;
	return 0;
}
