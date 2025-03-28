/*
class Solution {
    public:
    void helper(vector<int>&nums,vector<int>ans,vector<vector<int>>&finalans,int idx)
    {
        if(idx==nums.size())
        {
            finalans.push_back(ans);
            cout<<endl;
            return;
        }
        ans.push_back(nums[idx]);
        helper(nums,ans,finalans,idx+1);  //inclusion 
        ans.pop_back();
        helper(nums,ans,finalans,idx+1);    //exclusion
    }
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int>ans;
            vector<vector<int>>finalans;
            helper(nums,ans,finalans,0);
            return finalans;
        }
    };
*/
//https://leetcode.com/problems/subsets/