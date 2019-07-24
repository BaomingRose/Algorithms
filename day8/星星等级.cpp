/*红红观测星星都喜欢将他们放在笛卡尔坐标系内观测。
有一天红红和未来的大数学家可可一起夜观天象，
红红用一张纸将他观测的所有星星都画在了同一二维直角坐标系内，
他定义一颗星星左下方星星的数量为该星星的等级，现在他问可可给定星图上每个等级的星星数量。*/

#include<cstdio>
#include<cstring>
using namespace std;
const int M=32002;
#define lowbit(x) (x)&(-x)
int num[M];
void update(int x)
{
    for(;x<=M;x+=lowbit(x)) num[x]++;
}
int getsum(int x)
{
    int t=0;
    for(;x>0;x-=lowbit(x)) t+=num[x];
    return t;
}
int main()
{
    int n,i,x,y,res[M];
    while(scanf("%d",&n)!=EOF)
    {
        memset(res,0,sizeof(res));
        memset(num,0,sizeof(num));
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            x++;
            res[getsum(x)]++;
            update(x);
        }
        for(i=0;i<n;i++)
         printf("%d\n",res[i]);
    }
    return 0;
}

/*测试样例 
7
1 1
5 1
7 1
3 3
5 5
5 6
7 8*/
 
