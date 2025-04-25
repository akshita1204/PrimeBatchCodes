
/*
class Solution {
public:
int dp[11][2][2][1024];
bool check(int n,int mask)
{
  return !(mask & (1<<n));
}
int f(int idx,string &s,bool flag,bool lzero,int mask)
{
    if(idx>=s.size()) return 1;
    if(dp[idx][flag][lzero][mask]!=-1) return dp[idx][flag][lzero][mask];
    int mini=0;
    int maxi=flag ? s[idx]-'0' : 9;
    int ans=0;
    for(int i=mini;i<=maxi;i++)
    {
        if(lzero or check(i,mask))
        {
            int nmask=lzero && i==0 ? mask : mask | (1 << i);
            ans+=f(idx+1,s,flag && i==maxi,lzero && i==0,nmask);
        }
    }
    return dp[idx][flag][lzero][mask]=ans;
}
    int numDupDigitsAtMostN(int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        int val= f(0,s,true,true,0);
        return n-val+1;
    }
};

*/


//https://leetcode.com/problems/numbers-with-repeated-digits/description/