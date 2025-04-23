/*

class Solution {
public:
 bool pal(string &s,int i,int j)
  {
      while(i<j)
      {
          if(s[i]!=s[j]) return false;
          i++;
          j--;
      }
      return true;
  }

   int f(string &s,int idx, vector<int>&dp)
  {
      if(idx==s.length()) return 0;
      if(dp[idx]!=-1) return dp[idx];
      int ans=INT_MAX;
      for(int i=idx;i<s.length();i++)
      {
          if(pal(s,idx,i))
          {
              int cuts=1+f(s,i+1,dp);
              ans=min(ans,cuts);
          }
      }
      return dp[idx]=ans;
  }

    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n, -1);
        int ans=f(s,0,dp);
        return ans-1;
    }
};

*/





//https://leetcode.com/problems/palindrome-partitioning-ii/description/