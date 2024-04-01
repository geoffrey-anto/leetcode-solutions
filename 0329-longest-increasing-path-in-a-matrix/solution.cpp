class Solution {
public:
    int d[5] = {1, 0, -1, 0, 1};

    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp) {
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;

        for(int p=0; p<4; p++) {
            int dx = d[p] + i;
            int dy = d[p+1] + j;

            if(dx >= 0 and dx < matrix.size() and dy >= 0 and dy < matrix[0].size() && matrix[i][j] < matrix[dx][dy]) {
               ans = max(ans, 1 + dfs(dx, dy, matrix, dp));
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans = max(ans, dfs(i, j, matrix, dp) + 1);
            }
        }

        return ans;
    }
};
