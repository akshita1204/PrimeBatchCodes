#include <bits/stdc++.h>
using namespace std;

long long dp[20][3][11][3];
long long f(long long idx,string &s,bool flag,long long prev,bool lzero)
{
  if(idx>=s.size()) return 1;
  if(dp[idx][flag][prev+1][lzero]!=-1) return dp[idx][flag][prev+1][lzero];
  long long mini=0;
  long long maxi=flag ? s[idx]-'0' : 9;
  long long ans=0;
  for(int i=mini;i<=maxi;i++)
  {
    if(lzero or i!=prev) ans+=f(idx+1,s,flag && (i==maxi),i,lzero && (i==0));
  }
  return dp[idx][flag][prev+1][lzero]=ans;
}
int main() 
{
   long long a,b;
   cin>>a>>b;
   
   string s=to_string(a);
   string t=to_string(b);
   memset(dp,-1,sizeof(dp));
   long long x=f(0,s,true,-1,1);
   memset(dp,-1,sizeof(dp));
   long long y=f(0,t,true,-1,1);
   
   
   bool flag=true;
   for(int i=1;i<s.size();i++)
   {
     if(s[i]==s[i-1]) flag=false;
   }
   if(flag==false) cout<<y-x;
   else cout<<y-x+1;
   
}



//https://cses.fi/problemset/task/2220