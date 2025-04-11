/*
class Solution {
    public:
    int n,m,l;
    int dp[102][102][202];
    bool f(int i,int j,int k,string &a,string &b,string &c)
    {
        if(i==n and j==m and k==l) return true;
        if(k>=l) return false;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        bool res=false;
        if(a[i]==c[k]) res=f(i+1,j,k+1,a,b,c);
        if(res==true) return dp[i][j][k]=res;
        if(b[j]==c[k]) res=f(i,j+1,k+1,a,b,c);
        return dp[i][j][k]=res;
    }
        bool isInterleave(string s1, string s2, string s3) {
          n=s1.size();
          m=s2.size();
          l=s3.size();
          memset(dp,-1,sizeof(dp));
          return f(0,0,0,s1,s2,s3);  
        }
    };


*/
//https://leetcode.com/problems/interleaving-string/