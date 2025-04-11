/*
class Solution {
public:
vector<vector<int>>dp;
int f(string &a,string &b,int i,int j)
{
   if(i==a.size()) return b.size()-j;
   if(j==b.size()) return a.size()-i;
   if(dp[i][j]!=-1) return dp[i][j];
   int ans;
   if(a[i]==b[j])
   {
    ans=f(a,b,i+1,j+1);
   } 
   else
   {
    ans=1+min(f(a,b,i+1,j),f(a,b,i,j+1));
   }
   return dp[i][j]=ans;
}
    int minDistance(string word1, string word2) {
    int n=word1.length();
    int m=word2.length();
       dp.clear();
       dp.resize(n,vector<int>(m,-1));
       return f(word1,word2,0,0);

    }
};
*/ 
//https://leetcode.com/problems/delete-operation-for-two-strings/