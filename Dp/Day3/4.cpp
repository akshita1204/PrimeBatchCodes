#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
vector<vector<long long>>dp;
long long f(long long a,long long i,vector<long long>&c)
{
    if(a<0 or i>=(long long)c.size()) return 0;
    if(a==0) return 1;
    if(dp[a][i]!=-1) return dp[a][i];
    long long take=f(a-c[i],i,c);
    long long skip=f(a,i+1,c);
    return dp[a][i]=(take+skip)%mod;
}
    int main() {
        long long n,amount;
        cin>>n>>amount;
        vector<long long>coins(n);
        for(int i=0;i<n;i++) cin>>coins[i];
        dp.resize(amount+1,vector<long long>(n,-1));
        cout<<f(amount,0,coins);
    }



//https://cses.fi/problemset/task/1636