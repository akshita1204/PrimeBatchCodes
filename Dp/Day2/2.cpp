/*
class Solution {
public:
vector<int>dp;
int f(int i,string &s)
{
    if(i>=s.size()) return 1; // we have decoded the entire string 
    if(s[i]=='0') return 0;
    if(i==s.size()-1) return 1; //means we have reached the last char
    if(dp[i]!=-1) return dp[i];
    else if(s[i]=='1' || (s[i]=='2' && s[i+1]>=48 && s[i+1]<=54) )
     return dp[i]=f(i+1,s)+f(i+2,s);
    else return dp[i]=f(i+1,s);


}
    int numDecodings(string s) {
        int n=s.size();
        dp.resize(n,-1);
        return f(0,s);  
    }
};

*/



//https://leetcode.com/problems/decode-ways/description/