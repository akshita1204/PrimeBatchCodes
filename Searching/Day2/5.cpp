#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long>&v,long long mid)
{
  long long c=2;
  long long val=v[0];
  for(int i=1;i<v.size();i++)
  {
    if(v[i]>val+2*mid)
    {
      c--;
      val=v[i];
    }
    if(c<0) return false;
  }
  return true;
}


int main()
{
  long long t;
  cin>>t;
  while(t--)
  {
  long long n;
  cin>>n;
  vector<long long>v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  sort(v.begin(),v.end());
  int i=0,j=v[n-1]-v[0],ans=j;
  while(i<=j)
  {
    long long mid=(i+j)/2;
    if(check(v,mid))
    {
      ans=mid;
      j=mid-1;
    }
    else 
   {
      i=mid+1;
   }
  }
  cout<<ans<<endl;
  
  }
  
}

//https://codeforces.com/problemset/problem/1840/D