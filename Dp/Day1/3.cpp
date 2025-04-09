/*
class Solution {
public:
vector<int>dp;
int f(vector<int>&nums,int i)
{
if(i==nums.size()-1) return nums[i];
if(i==nums.size()-2) return max(nums[i],nums[i+1]);
if(dp[i]!=-1) return dp[i];
return dp[i]=max(nums[i]+f(nums,i+2),f(nums,i+1));
}
    int rob(vector<int>& nums) {
    int n=nums.size();
       dp.clear();
       dp.resize(n,-1);
       return f(nums,0); 
    }
};

*/

//https://leetcode.com/problems/house-robber/description/