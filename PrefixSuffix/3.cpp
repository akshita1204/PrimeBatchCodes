#include<bits/stdc++.h>
using namespace std;

long long maxi(long long a, long long b) {
    return (a > b) ? a : b;
}

int main()
{
  int n,p,q,r;
  cin>>n>>p>>q>>r;
  vector<long long>v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  vector<long long>pre(n);
  vector<long long>suf(n);
  pre[0]=v[0]*p;
  suf[n-1]=v[n-1]*r;

  for(int i=1;i<n;i++)
  {
    pre[i]=maxi(v[i]*p,pre[i-1]);
  }
  for(int i=n-2;i>=0;i--)
  {
    suf[i]=maxi(suf[i+1],v[i]*r);
  }
  long long ans=LLONG_MIN;
  for(int mid=0;mid<n;mid++)
  {
    long long cur=pre[mid]+q*v[mid]+suf[mid];
    ans=maxi(ans,cur);
  }
  cout<<ans<<endl;
  
  
}
//https://codeforces.com/problemset/problem/855/B