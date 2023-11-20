
class Solution {
public:
    int f(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<int>> &dp) {
        if(x == m-1 and y == n-1) {
            return grid[x][y];
        }

        if(x >= m or y >= n) {
            return 1e9;
        }

        if(dp[x][y] != -1) return dp[x][y];

        int v1 = 1e9;
        int v2 = 1e9;

        if(x < m) {
            v1 = (f(x+1, y, m, n, grid, dp)+grid[x][y]);
        }

        if(y < n-1) {
            v2 = (f(x, y+1, m, n, grid, dp)+grid[x][y]);
        }

        return dp[x][y] = min(v1, v2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, m, n, grid,dp);
    }
};
