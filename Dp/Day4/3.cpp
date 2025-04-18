/*
class Solution {
public:
int dp[505][505];
int f(string &s,string &t,int i,int j)
{ 
    if(i==s.length()) return t.length()-j;
    if(j==t.length()) return s.length()-i;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]) return dp[i][j]=f(s,t,i+1,j+1);
    return  dp[i][j]=min({1+f(s,t,i+1,j+1), // replacement
     1+f(s,t,i+1,j), //deletion
     1+f(s,t,i,j+1)  //addition 
     });
}
    int minDistance(string word1, string word2) {
       memset(dp,-1,sizeof dp);
       return f(word1,word2,0,0); 
    }
};
*/




//https://leetcode.com/problems/edit-distance/