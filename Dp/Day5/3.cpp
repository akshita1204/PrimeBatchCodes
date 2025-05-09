/*

class Solution {
public:

    int findNumberOfLIS(vector<int>& nums) {
      int n=nums.size();
      if(n==0) return 0;
      vector<int>dp(n,1);
      vector<int>count(n,1);
      int maxlen=1;
      for(int i=1;i<n;i++)
      {
        for(int j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
            {
                if(dp[i]==dp[j]+1)
                {
                    count[i]=count[i]+count[j];
                }
                else if(dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
            }
        }
        maxlen=max(maxlen,dp[i]);
      } 
      int ans=0;
      for(int i=0;i<n;i++)
      {
        if(dp[i]==maxlen) ans+=count[i];
      }
      return ans;
    }
};
*/

//https://leetcode.com/problems/number-of-longest-increasing-subsequence/