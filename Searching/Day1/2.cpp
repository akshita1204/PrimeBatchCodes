/*
class Solution {
public:
int fisrt(vector<int>& nums, int t)
{
    int low=0;
    int ans=-1;
    int high=nums.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==t)
        {
            ans=mid;
            high=mid-1;
        }
        else if(nums[mid]<t) low=mid+1;
        else high=mid-1;
    }
    return ans;
}
int last(vector<int>& nums, int t)
{
    int low=0;
    int high=nums.size()-1;
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==t)
        {
            ans=mid;
            low=mid+1;
        }
        else if(nums[mid]<t) low=mid+1;
        else high=mid-1;
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int>ans;
       int a=fisrt(nums,target);
       int b=last(nums,target);
       ans.push_back(a) ;
       ans.push_back(b);
       return ans;
    }
};

*/


//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/