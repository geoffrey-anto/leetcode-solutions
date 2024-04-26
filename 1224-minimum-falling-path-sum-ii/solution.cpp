class Solution {
public:
    // int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    //     if(i==matrix.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
        
    //     int upLeft = 1e8;
    //     if(j>0 and j < matrix[0].size()) upLeft = f(i+1, j-1, matrix, dp);
        
    //     int upRight = 1e8;
    //     if(j >= 0 and j<matrix[0].size()-1) upRight = f(i+1,j+1, matrix, dp);

    //     if(upLeft == 1e8 and upRight == 1e8) {
    //         upLeft = 0;
    //     }
        
    //     return dp[i][j] = matrix[i][j] + min(upLeft, upRight);
    // }
    
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int mn = 1e8;
    //     int n = matrix.size();
    //     int m = matrix[0].size();
    //     for(int i=0;i<m;i++){
    //         vector<vector<int>> dp(n, vector<int>(m, -1));
    //         mn = min(mn, f(0, i, matrix, dp));
    //     }

    //     return mn;
        
    //     vector<int> prev(m ,0);
    //     vector<int> curr(m, 0);
    
    //     for(int i=0;i<m;i++) prev[i]=matrix[0][i];
        
    //     for(int i=1;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             int upLeft = matrix[i][j];
    //             if(j-1>=0) upLeft+=prev[j-1];
    //             else upLeft = 1e8;

    //             int upRight = matrix[i][j];
    //             if(j+1<=m-1) upRight+=prev[j+1];
    //             else upRight = 1e8;


    //             curr[j] = min(upLeft, upRight);
    //         }
    //         prev=curr;
    //     }
    //     for(int c=0; c<m;c++){
    //         mn = min(mn, prev[c]);
    //     }
        
    //     return mn;
    // }

    int f(vector<vector<int>>& grid, int i, int j, vector<vector<int>>&dp){
        if(i == grid.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans =  INT_MAX;
        for(int k = 0; k < grid[0].size(); k++){
            if(j == k)
                continue;
            ans = min(ans, f(grid,i + 1, k, dp) + grid[i][j]);
        }
        return dp[i][j] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        const int n = grid.size();
        if(n == 1)
            return grid[0][0];
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int ans = INT_MAX;
        for(int j = 0; j < n; j++)
            ans = min(ans, f(grid, 0, j, dp));
        return ans;
    }
};
