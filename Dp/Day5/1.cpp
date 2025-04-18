/*



class Solution {
    public:
    int n;
    int dp[2501][2501];
    int f(vector<int>&nums,int idx,int prev)
    {
      if(idx>=n) return 0;
      if(prev!=-1 and dp[idx][prev]!=-1) return dp[idx][prev];
      //take 
      int take=0;
      if(prev==-1 or nums[prev]<nums[idx])
      {
        take=1+f(nums,idx+1,idx);
      }
      //skip
      int skip=f(nums,idx+1,prev);
      if(prev!=-1) return dp[idx][prev]=max(take,skip);
      return max(take,skip);
      
    }
        int lengthOfLIS(vector<int>& nums) {
            n=nums.size();
            memset(dp,-1,sizeof(dp));
            return f(nums,0,-1);       
        }
    };
*/
    //prev index par jo value hai wo cur idx ki value se km honi chahiye to take

    //https://leetcode.com/problems/longest-increasing-subsequence/description/