/*

class Solution {
public:

vector<int>tem;
void f(int i,vector<int>&nums,vector<int>&ans,vector<int>&dp)
{
    if(i>=nums.size())
    {
        if(ans.size()>tem.size())
        {
            tem=ans;
        }
        return;
    }
    
if((ans.size()==0 or nums[i]%ans.back()==0) && dp[i]<(int)ans.size()+1)
    {
        dp[i]=ans.size()+1;
        ans.push_back(nums[i]);
        f(i+1,nums,ans,dp);
        ans.pop_back();
    }
    f(i+1,nums,ans,dp);
}


    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());
        vector<int>dp(n,-1);
        f(0,nums,ans,dp);
        return tem;
    }
};
*/





//https://leetcode.com/problems/largest-divisible-subset/description/