/*
class Solution {
public:

int lower(vector<int>&nums,int target)
{
   int i=0,j=nums.size()-1;
   while(i<j)
   {
    int mid=i+(j-i)/2;
    if(nums[mid]<target) i=mid+1;
    else j=mid;
   }
   return i;
}

int upper(vector<int>&nums,int target)
{
   int i=0,j=nums.size()-1;
   while(i<j)
   {
    int mid=i+(j-i)/2;
    if(nums[mid]<=target) i=mid+1;
    else j=mid;
   }
   return i;
}

void dfs(vector<int>&nums,int i,int c,int path, vector<vector<int>>&sum)
{
    if(i>=nums.size())
    {
       sum[c].push_back(path);
       return;
    }
    dfs(nums,i+1,c+1,path+nums[i],sum);
    dfs(nums,i+1,c,path,sum);
}


    int minimumDifference(vector<int>& nums) {
      
      //cal the total sum
      int n=nums.size();
      int sum=accumulate(nums.begin(),nums.end(),0);
      int target=sum/2;
      int ans=INT_MAX;
      
      //make two arrays left and right
      vector<int>lnum(nums.begin(),nums.begin()+n/2); //first half
      vector<int>rnum(nums.begin()+n/2,nums.end()); //second half

      //arrays to store the sum of right and left part
      vector<vector<int>>lsum(n/2+1); //sum of firsthalf
      vector<vector<int>>rsum(n/2+1); //sum of secondhalf
      
      //to obtain the pair sum
      dfs(lnum,0,0,0,lsum);
      dfs(rnum,0,0,0,rsum);

      for(int i=0;i<n/2;i++)
      {
        sort(rsum[i].begin(),rsum[i].end());
        for(int l:lsum[i])
        {
            int lowidx=lower(rsum[n/2-i],target-l);
            int upidx=upper(rsum[n/2-i],target-l);
            
            //valid check
            if(lowidx<rsum[n/2-i].size())
            {
                ans=min(ans,abs(sum-2*(l+rsum[n/2-i][lowidx])));
            }
            if(upidx<rsum[n/2-i].size())
            {
                ans=min(ans,abs(sum-2*(l+rsum[n/2-i][upidx])));
            }
            if(lowidx>0)
            {
                ans=min(ans,abs(sum-2*(l+rsum[n/2-i][lowidx-1])));
            }
            if(upidx>0)
            {
                ans=min(ans,abs(sum-2*(l+rsum[n/2-i][upidx-1])));
            }
            
        }

      }
      return ans;
   
    }
};
*/
//https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/