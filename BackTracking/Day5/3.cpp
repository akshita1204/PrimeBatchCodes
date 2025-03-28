/*
class Solution {
public:
bool f(vector<vector<char>>& board,int i,int j,int n,int m,string &word,int w)
{
    if(w==word.length()) return true;
    if(i<0 or i>=n or j<0 or j>=m) return false;
    if(board[i][j]!=word[w]) return false;
    char ch=board[i][j];
    board[i][j]='0';
    bool right=f(board,i,j+1,n,m,word,w+1);
    bool left=f(board,i,j-1,n,m,word,w+1);
    bool up=f(board,i-1,j,n,m,word,w+1);
    bool down=f(board,i+1,j,n,m,word,w+1);
    board[i][j]=ch; //unmark
    return (right || left || up ||down);
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        //storing the indices where word[0]==board[i][j]
        vector<pair<int,int>>indices;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0]) 
                {
                    indices.push_back({i,j});
                }
            }
        }
        //check for all the indices present in the indices vector
        bool ans=false;
        for(auto i:indices)
        {
            ans=ans || f(board,i.first,i.second,n,m,word,0);
        }
        return ans;
    }
};

*/



//https://leetcode.com/problems/word-search/description/