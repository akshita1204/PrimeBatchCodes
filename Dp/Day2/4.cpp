/*
class Solution {
public:
vector<long long int>dp;
long long int m=1e9+7;
long long int f(int i,string &s)
{
    if(i>=s.length()) return 1;
    if(s[i]=='0') return 0;
    if(dp[i]!=-1) return dp[i];

    long long int c=f(i+1,s);
    if(s[i]=='*') c=(c*9)%m;

    if(i+1<s.length())
    {
        if(s[i]=='1' and s[i+1]=='*') c=(c+9*f(i+2,s)%m)%m;
        else if(s[i]=='1' and s[i+1]!='*') c=(c+f(i+2,s)%m)%m;
        
        else if(s[i]=='2' and s[i+1]=='*') c=(c+6*f(i+2,s)%m)%m;
        else if(s[i]=='2' and s[i+1]!='*')
        {
            if(s[i+1]<='6') c=(c+f(i+2,s)%m)%m;
        }

        else if(s[i]=='*' and s[i+1]=='*')
        {
         c=(c+9*f(i+2,s)%m)%m;
         c=(c+6*f(i+2,s)%m)%m;   
        }
        else if(s[i]=='*' and s[i+1]!='*')
        {
          c=(c+f(i+2,s)%m)%m;  
          if(s[i+1]<='6')  c=(c+f(i+2,s)%m)%m; 
        }
        
    }
    return dp[i]=c%m;
}
    int numDecodings(string s) {
       dp.resize(s.length(),-1);
       return f(0,s); 
    }
};

*/






//https://leetcode.com/problems/decode-ways-ii/description/