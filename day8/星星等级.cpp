/*���۲����Ƕ�ϲ�������Ƿ��ڵѿ�������ϵ�ڹ۲⡣
��һ�����δ���Ĵ���ѧ�ҿɿ�һ��ҹ������
�����һ��ֽ�����۲���������Ƕ�������ͬһ��άֱ������ϵ�ڣ�
������һ���������·����ǵ�����Ϊ�����ǵĵȼ����������ʿɿɸ�����ͼ��ÿ���ȼ�������������*/

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

/*�������� 
7
1 1
5 1
7 1
3 3
5 5
5 6
7 8*/
 
