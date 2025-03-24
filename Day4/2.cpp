#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    string s;
    cin>>s;

    int n = s.length();

    vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));

    vector<vector<bool>> pal(n,vector<bool> (n,true));

    for(int x=1;x<n;x++){
        int i=0;
        int j=x;
        while(i<n && j<n){
            pal[i][j] = (pal[i+1][j-1] && s[i]==s[j]);
            i++;
            j++;
        }
    }

    for(int i=n-1;i>=0;i--){
        
        long long c = 0;
        
        for(int j=i;j<n;j++){
            dp[i][j] = dp[i+1][j];
            
            if(pal[i][j]){
                c++;
            }
            dp[i][j] += c;
        }
    }

    

    int q;
    cin>>q;

    int x,y;
    while(q--){
        cin>>x>>y;
        printf("%lld\n",dp[x-1][y-1]);

    }

    return 0;
}

//https://codeforces.com/problemset/problem/245/H