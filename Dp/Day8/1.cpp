#include <bits/stdc++.h>
using namespace std;

int f(int idx,string &s,bool flag)
{
  if(idx>=s.size()) return 1;
  int mini=0;
  int maxi=flag ? s[idx]-'0' : 9;
  int ans=0;
  for(int i=mini;i<=maxi;i++)
  {
    ans+=f(idx+1,s,flag && (i==maxi));
  }
  return ans;
}
int main() 
{
   string s;
   cin>>s;
   cout<<f(0,s,true);
}

//Calculate the number of integers from 0 to a stoi(s);