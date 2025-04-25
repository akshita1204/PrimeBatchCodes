
/*
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dun) {
        int n = dun.size();
        int m = dun[0].size();
        vector<vector<int>>dp(n,vector<int>(m));

        dp[n-1][m-1] = max(1,1-dun[n-1][m-1]);

        //last col
        for(int i=n-2;i>=0;i--){
            dp[i][m-1] = max(1, dp[i+1][m-1]-dun[i][m-1]);
        }
        //last row 
        for(int i=m-2; i>=0; i--){
            dp[n-1][i] = max(1, dp[n-1][i+1]-dun[n-1][i]);
        }
        //rem grid
        for(int i=n-2; i>=0; i--){
            for(int j=m-2; j>=0; j--){
                dp[i][j] = max(1, min(dp[i][j+1], dp[i+1][j])-dun[i][j]);
            }
        }
        return dp[0][0];
    }
};

*/

//https://leetcode.com/problems/dungeon-game/description/