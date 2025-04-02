/*
class Solution {
    public:
    int f(vector<int>& nums, int k)
    {
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==k) ans= mid;
            //if left part is sorted
            if(nums[low]<=nums[mid])
            {
                if(nums[low]<=k and k<=nums[mid])
                {
                    high=mid-1;
                }
                else low=mid+1;
            }
            else //right part is sorted
            {
           if(nums[mid]<=k and k<=nums[high])
           {
            low=mid+1;
           }
           else high=mid-1;
            }
        }
        return ans;
    }
        int search(vector<int>& nums, int target) {
           int a=f(nums,target);
           return a; 
        }
    };

*/
//https://leetcode.com/problems/search-in-rotated-sorted-array/