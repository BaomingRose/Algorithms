/*题目描述
某省调查城镇交通状况,得到现有城镇道路统计表,表中列出了每条道路直接连通的城镇.
省政府"畅通工程"的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连,只要互相间接通过道路可达即可）.
问最少还需要建设多少条道路？ 
输入
测试输入包含若干测试用例.每个测试用例的第1行给出两个正整数,分别是城镇数目N(<1000)和道路数目M;
随后的M行对应M条道路,每行给出一对正整数,分别是该条道路直接连通的两个城镇的编号.为简单起见,城镇从1到N编号. 
注意:两个城市之间可以有多条道路相通也就是说 
3 3 
1 2 
1 2 
2 1 
这种输入也是合法的 
当N为0时,输入结束,该用例不被处理. 
输出
对每个测试用例,在1行里输出最少还需要建设的道路数目.
样例输入
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0
样例输出
1
0
2
998
提示
Huge input scanf is recommended.*/


#include <bits/stdc++.h>
using namespace std;

int Tree[1000];//并查集

int find_root(int x) {
    if(Tree[x] == -1)
        return x;
    else {//压缩路径
        int tmp = find_root(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int main() {
    int n, m;
    while(scanf("%d", &n) != EOF && n != 0) {
        scanf("%d", &m);
        for(int i = 1; i <= n; i++)
            Tree[i] = -1;//每个节点初始化为一个集合
        while(m--) {
            int a, b;
            scanf("%d%d", &a, &b);
            a = find_root(a);
            b = find_root(b);
            if(a != b)  Tree[a] = b;//若a,b不在一个连通分量(集合)中 则合并
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(Tree[i] == -1)
				ans++;//统计连通分量(集合)的个数
        printf("%d\n", ans-1);//n个连通分量只需n-1条边
    }

    return 0;
}

