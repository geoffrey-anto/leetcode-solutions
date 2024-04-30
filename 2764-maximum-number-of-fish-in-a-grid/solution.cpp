class Solution {
public:
    vector<pair<int,int>>dirs{{-1,0},{1,0},{0,-1},{0,1}};

    int f(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>> &vis) {
        vis[i][j] = true;

        int ans = 0;

        for(auto &d: dirs) {
            int dx = i + d.first;
            int dy = j + d.second;

            if(dx >= 0 and dx < n and dy >= 0 and dy < m and grid[dx][dy] and !vis[dx][dy]) {
                ans += grid[dx][dy] + f(dx, dy, n, m, grid, vis);
            }
        }

        return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool> (m, false));

        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] and grid[i][j]) {
                    ans = max(ans, grid[i][j] + f(i, j, n, m, grid, vis));
                } 
            }
        }

        return ans;
    }
};
