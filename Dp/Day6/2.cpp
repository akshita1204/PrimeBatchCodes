
/*

class Solution {
public:
int dp[105][105];
int f(int l,int r,vector<int>& cuts)
{
    if(r-l<2) return 0;
    int res=INT_MAX;
    if(dp[l][r]!=-1) return dp[l][r];
    for(int i=l+1;i<=r-1;i++)
    {
     int sum=(cuts[r]-cuts[l])+f(l,i,cuts)+f(i,r,cuts);
      res=min(res,sum);
    }
    return dp[l][r]=res;
}
    int minCost(int n, vector<int>& cuts) {
    memset(dp,-1,sizeof(dp));
    sort(cuts.begin(),cuts.end());
    cuts.insert(begin(cuts),0);
    cuts.push_back(n);
    int ans=f(0,cuts.size()-1,cuts); 
    return ans; 
    }
};

*/

//https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/