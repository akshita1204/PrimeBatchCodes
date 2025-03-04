#include<bits/stdc++.h>
using namespace std;

void f(vector<int>&v,int sum,int i,vector<vector<int>>&ans,vector<int>&cur)
{
   if(i>=v.size()) return;
   if(sum==0)
   {
     ans.push_back(cur);
     return;
   }
   if(sum<0) return;
   cur.push_back(v[i]);
   f(v,sum-v[i],i,ans,cur);
   cur.pop_back();
   f(v,sum,i+1,ans,cur);
}
int main()
{
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  int sum;
  cin>>sum;
  vector<int>cur;
  vector<vector<int>>ans;
  f(v,sum,0,ans,cur);
  for(int i=0;i<ans.size();i++)
  {
    for(int j=0;j<ans[i].size();j++)
    {
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
 
}
//https://leetcode.com/problems/combination-sum/