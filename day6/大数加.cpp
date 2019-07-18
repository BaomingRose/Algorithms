#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
string ans;

string num_push(string a,string b)
{
	ans.clear();
  int lena=a.size();
  int lenb=b.size();
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  int yu=0;
  for(int i=0;;i++)
  {
    if(i<lena&&i<lenb)
	{
      ans+=(yu+a[i]-'0'+b[i]-'0')%10+'0';
      yu=(yu+a[i]-'0'+b[i]-'0')/10;
    }else if(i<lena)
	{
      ans+=(yu+a[i]-'0')%10+'0';
      yu=(yu+a[i]-'0')/10;
    }else if(i<lenb)
	{
      ans+=(yu+b[i]-'0')%10+'0';
      yu=(yu+b[i]-'0')/10;
    }else if(yu!=0)
	{
      ans+=yu%10+'0';
      yu=yu/10;
    }else 
		break;
  }
  reverse(ans.begin(),ans.end());
  return ans;
}

string a,b;

int main()
{
  while(cin>>a>>b)
  {
    cout<<num_push(a,b)<<endl;
  }
  return 0;
}



