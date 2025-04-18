/*
class Solution {
public:
bool static compare(vector<int>&a,vector<int>&b)
{
   if(a[0]==b[0]) return a[1]>b[1];
   else return a[0]<b[0];
}
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),compare);
        int n=envelopes.size();
        vector<int>ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++)
        {
            int l=ans.size();
            if(envelopes[i][1]>ans[l-1])
            {
              ans.push_back(envelopes[i][1]);
            }
            else
            {
                int idx=int(lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin());
                ans[idx]=envelopes[i][1];
            }
        }
        return ans.size();
    }
};

*/


//https://leetcode.com/problems/russian-doll-envelopes/description/