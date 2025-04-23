/*
class Solution {
    public:
    int dp[305][305];
    int f(vector<int>&nums,int i,int j)
    {
        int maxi=0;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i+1;k<=j-1;k++)
        {
            int c=nums[i]*nums[j]*nums[k] + f(nums,i,k) + f(nums,k,j);
            maxi=max(maxi,c);
        }
        return dp[i][j]=maxi;
    }
        int maxCoins(vector<int>& nums) {
            nums.insert(nums.begin(),1);
            nums.push_back(1);
            memset(dp,-1,sizeof(dp));
            return f(nums,0,nums.size()-1);
        }
    };
*/




//https://leetcode.com/problems/burst-balloons/description/