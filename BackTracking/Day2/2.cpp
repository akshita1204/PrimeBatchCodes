#include<bits/stdc++.h>
using namespace std;
void f(vector<vector<int>>&ans,vector<int>&cur,int idx,vector<int>&v)
{
  ans.push_back(cur);
  for(int i=idx;i<v.size();i++)
  {
    if(i>idx and v[i-1]==v[i]) continue;
    cur.push_back(v[i]);
    f(ans,cur,i+1,v);
    cur.pop_back();
  }
}
int main()
{
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  vector<int>cur;
  vector<vector<int>>ans;
  f(ans,cur,0,v);
  for(int i=0;i<ans.size();i++)
  {
    for(int j=0;j<ans[i].size();j++)
    {
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
}