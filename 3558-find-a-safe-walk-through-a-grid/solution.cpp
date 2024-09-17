class Solution {
public:
    vector<int> DIRS = {0, 1, 0, -1, 0};
    int DIRS_N = 4;

    bool dfs(int i, int j, int h, vector<vector<int>> &grid, vector<vector<bool>> &vis, int n, int m, vector<vector<vector<int>>> &dp) {     
        if(h == 0) {
            return dp[i][j][h] = false;
        }

        if(dp[i][j][h] != -1) {
            return dp[i][j][h];
        }

        if(i == n-1 and j == m-1) {
            return  dp[i][j][h] = h >= 1;
        }

        vis[i][j] = true;

        for(auto d = 0; d < DIRS_N; d++) {
            int di = DIRS[d] + i;
            int dj = DIRS[d+1] + j;

            if(di >= 0 and di < n and dj >= 0 and dj < m and vis[di][dj] == false and (h - grid[di][dj]) > 0) {
                if(dfs(di, dj, h - grid[di][dj], grid, vis, n, m, dp)) {
                    return  dp[di][dj][h] = true;
                }
            }
        }

        vis[i][j] = false;

        return  dp[i][j][h] = false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        vector<vector<bool>> vis(grid.size(), vector<bool> (grid[0].size(), false));
        vector<vector<vector<int>>> dp(grid.size()+2, vector<vector<int>> (grid[0].size()+2, vector<int> (health + 1, -1)));

        return dfs(0, 0, health - grid[0][0], grid, vis, grid.size(), grid[0].size(), dp);
    }
};
