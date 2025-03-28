#include<bits/stdc++.h>
using namespace std;

bool count(vector<string>&s,vector<int>&v,string a)
{
  for(int i=0;i<s.size();i++)
  {
    int c=0;
    for(int j=0;j<a.size();j++)
    {
      if(s[i][j]==a[j]) c++;
    }
    if(c!=v[i]) return false;
  }
  return true;
}
void f(string a,int same,int i,int n,vector<string>&s,vector<int>&v,int &ans)
{
  if(i>=n)
  {
    if(same==0 and count(s,v,a)) ans++;
    return;
  }

  if(same>0) f(a,same-1,i+1,n,s,v,ans);
  if(a[i]=='0') a[i]='1';
  else a[i]='0';
  f(a,same,i+1,n,s,v,ans);
  if(a[i]=='0') a[i]='1';
  else a[i]='0';
  
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<string>s(m);
  vector<int>v(m);
  for(int i=0;i<m;i++)
  {
    cin>>s[i]>>v[i];
  }
  int ans=0;
  f(s[0],v[0],0,n,s,v,ans);
  cout<<ans<<endl;
}