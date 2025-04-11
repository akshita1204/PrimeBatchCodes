
/*
class Solution {
public:
int dp[505][505];
int f(int i,int j,string &s)
{
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]) return dp[i][j]= f(i+1,j-1,s);
    return dp[i][j]=1+ min(f(i+1,j,s),f(i,j-1,s));
}
    int minInsertions(string s) {
       int n=s.length();
       memset(dp,-1,sizeof(dp));
       return f(0,n-1,s); 
    }
};
*/



//https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/