#include <bits/stdc++.h>
using namespace std;

vector<int>dp;
int dfs(vector<vector<int>>&adj,int node,int par)
{
  int size=1;
  if(dp[node]!=-1) return dp[node];
  for(auto child:adj[node])
  {
    if(child!=par) size+=dfs(adj,child,node);
  }
  return dp[node]=size;
}

int main()
{
  int n;
  cin>>n;
  vector<vector<int>>adj(n);
  for(int i=1;i<n;i++)
  {
    int p;
    cin>>p;
    p--;
    adj[i].push_back(p);
    adj[p].push_back(i);
  }
  dp.assign(n,-1);
  dfs(adj,0,-1);
  
  for(int i=0;i<n;i++)
  {
    cout<<dp[i]-1<<" ";
  }
  
}
//https://cses.fi/problemset/task/1674