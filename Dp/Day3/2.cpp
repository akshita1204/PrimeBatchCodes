#include<bits/stdc++.h>
using namespace std;

int dp[1000001];
int f(int target,vector<int>&v)
{
  if(target==0) return 0;
  if(target<0) return INT_MAX;
  if(dp[target]!=-1) return dp[target];
  int ans=INT_MAX;
  for(int i=0;i<v.size();i++)
  {
    int c=f(target-v[i],v);
    if(c!=INT_MAX) ans=min(ans,c+1);
  }
  return dp[target]=ans;
}
int main()
{
  int n,k;
  cin>>n>>k;
  vector<int>v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  
  memset(dp,-1,sizeof(dp));
  int ans=f(k,v);
  if(ans==INT_MAX) cout<<-1<<endl;
  else cout<<ans<<endl;
}
//https://cses.fi/problemset/task/1634