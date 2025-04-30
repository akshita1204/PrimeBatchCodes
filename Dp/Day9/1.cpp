/*
class Solution {
public:
int mod=1e9+7;

    int distinctSubseqII(string s) {
        vector<int>dp(26);
        for(char ch:s)
        {
            int val=ch-'a';
            dp[val]=accumulate(dp.begin(),dp.end(),1l)%mod;
            //dp[0]=1=>4
            //dp[1]=2
        }
        return accumulate(dp.begin(),dp.end(),0l)%mod; //6 for aba
    }
};
 
/*
ab=3
abc=3+3+1 
formula for rep char is 2*x+1


*/

//https://leetcode.com/problems/distinct-subsequences-ii/