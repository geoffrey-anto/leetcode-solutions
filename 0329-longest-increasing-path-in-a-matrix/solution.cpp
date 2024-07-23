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

    string path(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if(dp[i][j] == 0) {
            return to_string(matrix[i][j]);
        }

        for(int p=0; p<4; p++) {
            int dx = d[p] + i;
            int dy = d[p+1] + j;

            if(dx >= 0 and dx < matrix.size() and dy >= 0 and dy < matrix[0].size() && (dp[i][j] == dp[dx][dy] + 1)) {
               return to_string(matrix[i][j]) + path(dx, dy, matrix, dp);
            }
        }

        return "";
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

        bool isFound = false;

        // Trace Path
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dp[i][j] == ans - 1) {
                    // cout << path(i, j, matrix, dp) << endl;
                    isFound = true;

                    if(isFound) {
                        break;
                    }
                }
                if(isFound) {
                    break;
                }
            }
        }

        return ans;
    }
};
