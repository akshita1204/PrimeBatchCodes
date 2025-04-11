/*class Solution {
public:
vector<vector<int>>dp;
bool f(string&s,string&p,int i,int j)
{
    if(j==p.length()) return i==s.length();
    if(dp[i][j]!=-1) return dp[i][j];
    bool firstcharmatch=false;
    if(i<s.length() and (s[i]==p[j] or p[j]=='.')) firstcharmatch=true;
//agar s[i]==p[j] hoga yaa fir p[j] par . hoga to match karega kisi se 
    if(p[j+1]=='*')
    {
        bool ntake=f(s,p,i,j+2);
        bool take=firstcharmatch && f(s,p,i+1,j);
        return dp[i][j]=take || ntake;
    }
    return dp[i][j]=firstcharmatch && f(s,p,i+1,j+1);
}
    bool isMatch(string s, string p) {
       int n=s.length(), m=p.length();
       dp.resize(n+1,vector<int>(m+1,-1));
       return f(s,p,0,0); 
    }
}; */

//https://leetcode.com/problems/regular-expression-matching/