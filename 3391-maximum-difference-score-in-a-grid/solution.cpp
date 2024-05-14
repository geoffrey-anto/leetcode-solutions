class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, int n, int m, vector<vector<int>>& dp) {
        if (i >= n or j >= m) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int a = -1e9;
        int b = -1e9;

        if (i + 1 < n) { // bottom
            a = grid[i + 1][j] - grid[i][j] + f(i + 1, j, grid, n, m, dp);
        }

        if (j + 1 < m) { // right
            b = grid[i][j + 1] - grid[i][j] + f(i, j + 1, grid, n, m, dp);
        }

        int c = max(a, b);

        return dp[i][j] = max(0, c);
    }

    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int mx = -1e9;

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mx = max(mx, f(i, j, grid, n, m, dp));
            }
        }


        if(mx == 0) {
            int curr = -1e9;

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(i+1 < n) {
                        curr = max(curr, (grid[i+1][j] - grid[i][j]));
                    }

                    if(j+1 < m) {
                        curr = max(curr, (grid[i][j+1] - grid[i][j]));
                    }
                }
            }

            return curr;
        }

        return mx;
    }
};
