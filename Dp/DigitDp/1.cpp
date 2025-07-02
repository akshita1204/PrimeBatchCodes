#include <bits/stdc++.h>
using namespace std;

long long dp[500][500];

long long f(long long n,long long sum,bool tc) {
    if(sum<0) return 0;
    if(n==0) return sum==0; 
    if(dp[n][sum]!= -1) return dp[n][sum];

    long long ans=0;
    for(long long i=0;i<=9;i++) {
        ans+=f(n-1,sum-i);
    }
    return dp[n][sum]=ans;
}

int main() {
    long long n,sum;
    cin>>n>>sum;
    memset(dp,-1,sizeof(dp));
    cout<<f(n,sum)<<endl; 
    return 0;
}
