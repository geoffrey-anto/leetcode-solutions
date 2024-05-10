class Solution {
public:
    vector<int> dirs = {0, 1, 0, -1, 0};

    int f(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &vis) {
        int ans = 0;
        vis[i][j] = true;

        for(int d=0; d<4; d++) {
            int dx = i + dirs[d];
            int dy = j + dirs[d+1];

            if(dx >= 0 and dx < grid.size() and dy >= 0 and dy < grid[0].size() and !vis[dx][dy] and grid[dx][dy]) {
                ans = max(ans, grid[dx][dy] + f(grid, dx, dy, vis));
            }
        } 

        vis[i][j] = false;

        return ans;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) {
                    continue;
                }
                vector<vector<bool>> vis(n, vector<bool>(m, false));
                ans = max(ans, grid[i][j] + f(grid, i, j, vis));
            }
        }

        return ans;
    }
};
