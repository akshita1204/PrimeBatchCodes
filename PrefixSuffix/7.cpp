#include<bits/stdc++.h>
using namespace std;

int get(int s,int t,int c)
{
  return (s+t)%(c+1);
}

int main()
{
  int n,q,c;
  cin>>n>>q>>c;
  vector<tuple<int,int,int>>stars(n);
  for(int i=0;i<n;i++)
  {
    int xi,yi,si;
    cin>>xi>>yi>>si;
    stars[i]=make_tuple(xi,yi,si);
  }
  vector<vector<vector<int>>>brightness(c+1,vector<vector<int>>(101,vector<int>(101,0)));
  //t can vary from 0 to c
  for(auto star:stars)
  {
    int xi,yi,si;
    tie(xi,yi,si)=star;
    for(int t=0;t<=c;t++)
    {
      brightness[t][xi][yi]+=get(si,t,c);
    }
  }
  //prefix sum 
  vector<vector<vector<int>>>pre(c+1,vector<vector<int>>(101,vector<int>(101,0)));
  for(int t=0;t<=c;t++)
  {
    for(int i=1;i<=100;i++)
    {
      for(int j=1;j<=100;j++)
      {
        pre[t][i][j]=brightness[t][i][j] + pre[t][i-1][j] + pre[t][i][j-1] - pre[t][i-1][j-1];
      }
    }
  }
  
  while(q--)
  {
    int t,x1,y1,x2,y2;
    cin>>t>>x1>>y1>>x2>>y2;
    t=t%(c+1);
    int ans=pre[t][x2][y2] - pre[t][x1-1][y2] - pre[t][x2][y1-1] + pre[t][x1-1][y1-1];
    cout<<ans<<endl;
  }
  return 0;
  
}

//https://codeforces.com/problemset/problem/835/C