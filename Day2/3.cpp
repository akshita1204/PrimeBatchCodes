#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&v,int sum,int i)
{
  if(i==v.size()) return sum==0;
  return f(v,sum-v[i],i+1) + f(v,sum,i+1);
}
int main()
{
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  int sum;
  cin>>sum;
  cout<<f(v,sum,0);
 
}