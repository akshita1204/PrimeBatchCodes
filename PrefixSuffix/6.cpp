/*
class NumMatrix {
public:
vector<vector<int>>mat;
    NumMatrix(vector<vector<int>>& matrix) {
       int n=matrix.size();
       int m=matrix[0].size();
       mat=matrix;
       //row wise cal
       for(int i=0;i<n;i++)
       {
        for(int j=1;j<m;j++)
        {
            mat[i][j]=mat[i][j]+mat[i][j-1];
        }
       }
       //col wise cal
        for(int i=1;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            mat[i][j]=mat[i-1][j]+mat[i][j];
        }
       }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=mat[row2][col2];
        if(row1>=1) sum-=mat[row1-1][col2];
        if(col1>=1) sum-=mat[row2][col1-1];
        if(row1>=1 and col1>=1) sum+=mat[row1-1][col1-1];
        return sum;

    }
};
 */

 //https://leetcode.com/problems/range-sum-query-2d-immutable/
