/*

class Solution {
    public:
    bool ispal(string&s,int l,int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void f(string &s,int idx,vector<string>&cur,vector<vector<string>>&ans)
    {
        if(idx==s.length())
        {
            ans.push_back(cur);
            return;
        }
        for(int i=idx;i<s.size();i++)
        {
            if(ispal(s,idx,i))
            {
                cur.push_back(s.substr(idx,i-idx+1));
                f(s,i+1,cur,ans);
                cur.pop_back();
            }
        }
    }
        vector<vector<string>> partition(string s) {
            vector<vector<string>>ans;
            vector<string>cur;
            f(s,0,cur,ans);
            return ans;
    
        }
    };
*/
//https://leetcode.com/problems/palindrome-partitioning/