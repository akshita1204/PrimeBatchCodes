#include <bits/stdc++.h>
using namespace std;

long long dp[500][500][3];


long long f(long long n,long long sum,string& r,bool tc) {
    if(sum<0) return 0;
    if(n==0) return sum==0; 
    if(dp[n][sum][tc]!= -1) return dp[n][sum][tc];
    
    long long limit= tc==true ? r[r.size()-n]-'0' : 9;

    long long ans=0;
    for(long long i=0;i<=limit;i++) {
      bool nc=false;
      if(i==limit && tc==1) nc=true;
        ans+=f(n-1,sum-i,r,nc);
    }
    return dp[n][sum][tc]=ans;
}

int main() {
    long long n,sum;
    cin>>n>>sum;
    string l="3347";
    string r="7463";
    memset(dp,-1,sizeof(dp));
    long long a=f(n,sum,r,true);
    memset(dp,-1,sizeof(dp));
    long long b=f(n,sum,l,true); //we have to take l-1 but I have changed it in l
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<a-b<<endl;
    return 0;
}
