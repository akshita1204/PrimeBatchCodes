#include <bits/stdc++.h>
using namespace std;
bool valid(vector<int>&nums,int mid,int k)
{
    int st=1,cursum=0;
    for(int ele:nums)
        {
            if(cursum+ele>mid)
            {
                st++;
                cursum=ele;
            }
            else cursum+=ele;
            if(st>k) return false;
        }
    return true;
}

int f(vector<int>&nums,int k)
{
    if(k>nums.size()) return 0;
    int i=*max_element(nums.begin(),nums.end());
    int j=accumulate(nums.begin(),nums.end(),0);
    int ans=0;
    while(i<=j)
    {
        int mid=(i+j)/2;
       if(valid(nums,mid,k)==true)
       {
           ans=mid;
           j=mid-1;
       }
       else i=mid+1;
    }
    return ans;
}
int main() {
    // your code goes here
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    int k;
    cin>>k;
  
    cout<<f(nums,k);
}









//https://dashboard.programmingpathshala.com/renaissance/practice/question?questionId=106&sectionId=1&moduleId=2&topicId=6&subtopicId=82&assignmentId=17