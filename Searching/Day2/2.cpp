/*
class Solution {
    public:
    int f(vector<int>&nums)
    {
        int low=0;
        int high=nums.size()-1;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[low]<=nums[high]) 
            {
                ans=min(ans,nums[low]);
                break;
            }
            //if left part is sorted
          if(nums[low]<=nums[mid])
          {
            ans=min(ans,nums[low]);
            low=mid+1;
          }
          else
          {
            ans=min(ans,nums[mid]);
            high=mid-1;
    
          }
        }
        return ans;
    }
        int findMin(vector<int>& nums) {
          int a=f(nums);
          return a;  
        }
    };
*/
//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/