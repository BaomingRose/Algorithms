/*�� n ���ڵ㣬���Ϊ 1~n���� m ���ߣ�ÿ���߶���һ�����롣����֮�����ֻ�� 1 ���ߡ�
��������Ҫѡȡ n-1 ���ߣ�ʹ�����е㶼������������ͨ·��n-1 ���߾���֮��ԽС����Խ�ߡ�
���������ʶ�������������С�������ģ�����ÿ���˵Ĵ𰸲�����ͬ��������ݵ��۷�����ɳ��˴𰸣�
Ȼ�������ǵȴ����������ꡣ���������Ѿ��ҵ��˾�����̵�1�ַ�������������̫������Ϭ�ˣ���һģһ����
������õ� 2 ��������������һ�ַ���������֮��Խ��Խ�ã������ܺ����õĽ����ͬ��
һ���߲�ͬ������Ϊ��ͬ������Ҳ������ -1����Ȼ����һ�������������õķ�����û�з��������̾��룬
����ʾ��ͼû����С������������� -1����֮���õķ��������Ž��һ�֡�
����
���ڶ������ݣ���һ��һ�������� t����ʾ�� t �����ݡ�
ÿ�����ݵ�һ������������ n �� m��2 �� n �� 100��1 �� m �� 1000)��֮�� m �У�
ÿ������������ s��e��w����ʾ s �� e ��˫��·��ȨֵΪ w��
���
�����С��������ֵ��������ڶ����С�����������һ���������С������������С�����������-1���������������� -1��
��������
1
3 3
3 1 3
1 2 1
2 3 2
�������
4
*/
/*����һ����С����������Ŀ������С�������Ļ����ϼ�һЩ�����ͺ��ˡ�
ע���С�����������ڵ�������ǣ��������ͼ����С��������û�У�����һ�ֿ��ܾ���������Ȩֵһ������С��������
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn=0x3f3f3f3f;
int map[105][105];
int vis[105];
int dis[105];
int per[105];
int mapvis[105][105];
int max_ab[105][105];
int ans,ans1;

void init() {
    for(int i = 0; i < 105; i++) {
        vis[i] = 0;
        for(int j = 0; j < 105; j++) {
            map[i][j] = maxn;
            mapvis[i][j] = 0;
        }
    }
    ans = 0;
	ans1 = maxn;
}
void prim(int n) {
    vis[1] = 1;
    for(int i = 1; i <= n; i++) {
        dis[i] = map[1][i];
        per[i] = 1;
    }
    for(int i = 1; i < n; i++) {
        int minn = maxn, g;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && minn > dis[j]) {
                minn = dis[j];
                g = j;
            }
        }
        ans += minn;
        vis[g] = 1;
        mapvis[g][per[g]] = mapvis[per[g]][g] = 1;
        for(int k = 1; k <= n; k++) {
            if(vis[k] && k != g) {
                max_ab[k][g] = max_ab[g][k] = max(max_ab[per[g]][k], dis[g]);
            }
            if(!vis[k]) {
                if(map[g][k] < dis[k]) {
                    dis[k] = map[g][k];
                    per[k] = g;
                }
            }
        }
    }
    for(int i = 1; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(!mapvis[i][j] && map[i][j] != maxn) {
                ans1 = min(ans + map[i][j] - max_ab[i][j], ans1);
            }
        }
    }
}
int main() {
    int t, n, m;
    scanf("%d", &t);
    while(t--) {
        init();
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i++) {
            int xx, yy, vv;
            scanf("%d%d%d", &xx, &yy, &vv);
            map[xx][yy] = map[yy][xx] = vv;
        }
        prim(n);
        if(ans == ans1 || ans1 == maxn)
			printf("-1\n");
        else printf("%d\n", ans1);
    }
    return 0; 
}


