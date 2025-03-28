#include<bits/stdc++.h>
using namespace std;
void f(vector<vector<int>>&ans,vector<int>&cur,int idx,vector<int>&v)
{
  if(idx>=v.size()) 
  {
    ans.push_back(cur);
    //cout<<cur<<endl;
    return;
  }
  cur.push_back(v[idx]);
  f(ans,cur,idx+1,v);
  cur.push_back(v[idx]);
  f(ans,cur,idx+1,v);
  cur.pop_back();
  cur.pop_back();
  f(ans,cur,idx+1,v);
  
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