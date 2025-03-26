
/**
 class Solution {
public:
bool isvalid(vector<vector<char>>&board,int row,int col,char ch)
{
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==ch) return false;
        else if(board[i][col]==ch) return false;
        else if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch) return false;
    }
    return true;
}
bool f(vector<vector<char>>& board,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]=='.')//means we have to fill it 
            {
               for(char ch='1';ch<='9';ch++)
               {
                if(isvalid(board,i,j,ch))
                {
                    board[i][j]=ch;
                    if(f(board,n)) return true;
                    else board[i][j]='.';
                }
               } 
               return false;
            }
        }
    }
    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
       int n=board.size();
       f(board,n); 
    }
};
 */

//https://leetcode.com/problems/sudoku-solver/