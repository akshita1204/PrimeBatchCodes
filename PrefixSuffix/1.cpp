#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  vector<int>pre(n);
  vector<int>suf(n);
  int mini=INT_MAX;
  int maxi=INT_MIN;
  for(int i=0;i<n;i++)
  {
    if(mini>v[i])
    {
      mini=v[i];
    }
    pre[i]=mini;
  }
  for(int i=n-1;i>=0;i--)
  {
    if(maxi<v[i]) maxi=v[i];
    suf[i]=maxi;
  }
  for(int i=1;i<n-1;i++)
  {
    if(v[i]>pre[i] and v[i]<suf[i]) 
    {
      cout<<"True"<<endl;
      break;
    }
  }
  return 0;
}
