/*�������һ�Ŵ�a�зɵ�c�еĻ�Ʊ�����ҵ��ǣ�û��ֱ�ɺ��ࡣ���кܶ��a�е�b�У���b�е�c�еĺ��ࡣ
��a�е�b����n�����࣬������ʱ��a1��a2��a3 ����an��ɣ�����taʱ��󵽴�b�С�
��b�е�c����n�����࣬������ʱ��b1��b2��b3����bm��ɣ�����tbʱ��󵽴�c�С�
ת����ʱ����Ժ��Բ��ƣ��������Ե��ҽ���bj��ai+taʱ�����Դ�a�е�b�е�i�η��кʹ�b�е�c�е�j�η��С�
��������ȡ��k�κ��ࡣ�����ȡ���˺��࣬���Ͳ���ʹ������
�����Ҫ��������ؽ���c�У�������������������ؽ���c�С�
��������ŵ�ȡ����k�κ��࣬�����쵽��c������ʱ�䡣
��������ȡ��k������ٵĺ��࣬����ʹ����޷�����c�У������- 1��*/

#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
int a[maxn],b[maxn];
int lower(int l,int r,int n){
  while(l<=r){
    //cout<<l<<" "<<r<<endl;
    int mid=(l+r)/2;
    if(n>b[mid]) l=mid+1;
    else r=mid-1;
  }
  return l;
}
int main(){
  int n,m,ta,tb,k;
  scanf("%d %d %d %d %d", &n, &m, &ta, &tb, &k);
  for(int i=0;i<n;i++) scanf("%d", &a[i]);
  for(int i=0;i<n;i++) a[i]+=ta;
  for(int i=0;i<m;i++) scanf("%d", &b[i]);
  if(k>=min(n,m)){
    printf("-1\n");
    return 0;
  }
  int ans=0;
  for(int i=0;i<=k;i++){
    int p=lower(0,m-1,a[i]);
    p+=k-i;
    if(p>=m){
      printf("-1\n");
      return 0;
    }
    ans=max(ans,b[p]+tb);
  }
  printf("%d\n", ans);
  return 0;
}


