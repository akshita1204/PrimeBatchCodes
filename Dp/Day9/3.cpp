/*
class Solution {
public:
#define ll long long int 
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<ll,ll>>dp(n);
        int ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                ll dif=(ll)nums[i]-(ll)nums[j];
                if(dp[j].find(dif)!=dp[j].end())
                {
                    ans+=dp[j][dif];
                }
                dp[i][dif]+=dp[j][dif]+1;
            }
        }
        return ans;
        
    }
};
*/
//https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/