#include <bits/stdc++.h>
using namespace std;

long long dp[500][500][3];
string r;

long long f(long long n,long long sum,bool tc) {
    if(sum<0) return 0;
    if(n==0) return sum==0; 
    if(dp[n][sum][tc]!= -1) return dp[n][sum][tc];
    
    long long limit= tc==true ? r[r.size()-n]-'0' : 9;

    long long ans=0;
    for(long long i=0;i<=limit;i++) {
      bool nc=false;
      if(i==limit && tc==true) nc=true;
        ans+=f(n-1,sum-i,nc);
    }
    return dp[n][sum][tc]=ans;
}

int main() {
    long long n,sum;
    cin>>n>>sum;
    r="7463";
    memset(dp,-1,sizeof(dp));
    cout<<f(n,sum,true)<<endl; 
    return 0;
}
