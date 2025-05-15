#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
  if(a%2==0 && b%2!=0) 
  {
    return true;
  }
  if(a%2!=0 && b%2==0)
  {
    return false;
  }
  if(a%2==0 and b%2==0)
  {
    return a<b;
  }
  if(a%2!=0 and b%2!=0)
  {
    return a>b;
  }
  
}

int main()
{
 int n;
 cin>>n;
 vector<int>v(n);
 for(int i=0;i<n;i++) cin>>v[i];
 sort(v.begin(),v.end(),cmp);
 for(int i=0;i<n;i++)
 {
   cout<<v[i]<<" ";
 }
}

//Sort the array such that even comes before odd and even are in increasing and odd are in decreasing