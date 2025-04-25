/*
class Solution {
public:
vector<vector<int>>dp;
int f(int i,int j,vector<vector<int>>& matrix)
{
   int n=matrix.size();
   int m=matrix[0].size();
   if(i<0 or j<0 or i>=n or j>=m) return INT_MIN;
   if(dp[i][j]!=-1) return dp[i][j];
   int ans=1;
   if(i+1<n and matrix[i][j]<matrix[i+1][j])
   {
    ans=max(ans,1+f(i+1,j,matrix));
   }
   if(j+1<m and matrix[i][j]<matrix[i][j+1])
   {
    ans=max(ans,1+f(i,j+1,matrix));
   }
   if(i-1>=0 and matrix[i-1][j]>matrix[i][j])
   {
    ans=max(ans,1+f(i-1,j,matrix));
   }
   if(j-1>=0 and matrix[i][j-1]>matrix[i][j])
   {
    ans=max(ans,1+f(i,j-1,matrix));
   }
   return dp[i][j]=ans;  

}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        dp.resize(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,f(i,j,matrix));
            }
        }
        return ans;
    }
};

*/

//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/