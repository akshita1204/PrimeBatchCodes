/*
class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {
            int n=nums.size();
            vector<int>pre(n);
            vector<int>suf(n);
            int maxi=INT_MIN, mini=INT_MAX;
            for(int i=0;i<n;i++)
             {
             if(mini>nums[i])
             {
             mini=nums[i];
            }
            pre[i]=mini;
             }
           for(int i=n-1;i>=0;i--)
           {
            if(maxi<nums[i]) maxi=nums[i];
            suf[i]=maxi;
            }
    
            for(int i=1;i<n-1;i++)
            {
                if(nums[i]>pre[i] and nums[i]<suf[i]) return true;
            }
            return false;
        }
    };
    */
   
    //334. Increasing Triplet Subsequence