class Solution {
public:
    vector<pair<int, int>> dir = {
        {-1, 1},
        {1, 1},
        {0, 1}
    };

    int f(int i, int j, vector<vector<int>>& grid, int n, int m, vector<vector<int>> &dp) {

        int ans = 0;

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        for(int d=0; d<3; d++) {
            int nx = i+dir[d].first;
            int ny = j+dir[d].second;

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] > grid[i][j]) {
                ans = max(ans, 1+f(nx, ny, grid, n, m, dp));
            }
        }

        return dp[i][j] = ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));

        int mx = 0;
        
        for(int i=0; i<n; i++) {
            f(i, 0, grid, n, m, dp);
        }
        
        for(int i=0; i<n; i++) {
            mx = max(dp[i][0], mx);
        }

        return mx;
    }
};