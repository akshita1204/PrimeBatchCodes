#include<bits/stdc++.h>
using namespace std;

int ct[100]={0};
bool cmp(int a,int b)
{
  if(ct[a]==ct[b]) return a>b;
  else return ct[a]>ct[b];
}

int main()
{
 int n;
 cin>>n;
 vector<int>v(n);
 for(int i=0;i<n;i++) cin>>v[i];
 for(int i=0;i<n;i++)
 {
   ct[v[i]]++;
 }
 sort(v.begin(),v.end(),cmp);
 for(int i=0;i<n;i++)
 {
   cout<<v[i]<<" ";
 }
}

//Need to correct 