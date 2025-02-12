#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    vector<vector<int>>pre(n+1,vector<int>(10,0));
    //prefix array
    for(int i=0;i<n;i++)
    {
        for(int dig=0;dig<10;dig++)
        {
            pre[i+1][dig]=pre[i][dig];
        }
        pre[i+1][s[i]-'0']++;
    }
    //suffix array
    vector<vector<int>>suf(n+1,vector<int>(10,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int dig=0;dig<10;dig++)
        {
            suf[i][dig]=suf[i+1][dig];
        }
       suf[i][s[i]-'0']++;
    }
    //ans com
    int ans=0;
    for(int i=1;i<n-1;i++)
    {
        for(int dig=0;dig<10;dig++)
        {
            int x=pre[i][dig];
            int y=suf[i+1][dig];
            ans+=x*y;
        }
    }
    cout<<ans<<endl;
}
