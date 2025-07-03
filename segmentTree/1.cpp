#include <bits/stdc++.h>
using namespace std;

const int n=1e5;
int arr[n],tree[4*n];
int buildTree(int node, int ss,int se)
{
  
  if(se==ss)
  {
    tree[node]=arr[ss];
    return tree[node];
  }
  int mid=ss+(se-ss)/2;
  int lval=buildTree(2*node,ss,mid);
  int rval=buildTree(2*node+1,mid+1,se);
  tree[node]=lval + rval;
  return tree[node];
}


void update(int idx,int val,int node,int ss,int se)
{
  
  if(ss==se && se==idx)
  {
    arr[idx]=val;
    tree[node]=val;
    return;
  }
  int mid=ss+(se-ss)/2;
  if(idx<=mid) update(idx,val,2*node,ss,mid);
  else update(idx,val,2*node+1,mid+1,se);
  tree[node]=tree[2*node]+tree[2*node+1];
}


int query(int l,int r,int node,int ss,int se)
{
  //complete overlap 
  if(ss>=l && se<=r)
  {
    return tree[node];
  }
  //no overlap
  else if(se<l or ss>r)
  {
    return 0;
  }
  //partial overlap
  else
  {
    int mid=ss+(se-ss)/2;
    int lval=query(l,r,2*node,ss,mid);
    int rval=query(l,r,2*node+1,mid+1,se);
    return lval+rval;
  }
}

int main()
{
   int m;
   cin>>m;
  for(int i=0;i<m;i++)
  {
    cin>>arr[i];
  }
  int x=buildTree(1,0,n-1);
  cout<<x<<endl;
  
  int idx,val;
  cin>>idx>>val;
  update(idx,val,1,0,n-1);
  
  int y=buildTree(1,0,n-1);
  cout<<y<<endl;
  
  int z=query(0,3,1,0,n-1);
  cout<<z<<endl;
  
}