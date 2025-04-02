/*

class Solution {
    public:
    int fmax(vector<int>&nums)
    {
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,nums[i]);
        }
    return ans;
    }
    int sum(vector<int>&nums)
    {
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
        }
    return s;
    }
    int f(vector<int>&nums,int mid)
    {
        int s=1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(sum+nums[i]<=mid) sum+=nums[i];
            else
            {
                s++;
                sum=nums[i];
            }
        }
    return s;
    }
        int splitArray(vector<int>& nums, int k) {
         int n=nums.size();
         int low=fmax(nums);
         int high=sum(nums);
         while(low<=high)
         {
         int mid=(low+high)/2;
         int a=f(nums,mid);
         if(a>k) low=mid+1;
         else high=mid-1;
         } 
         return low;  
        }
    };

*/



//https://leetcode.com/problems/split-array-largest-sum/description/