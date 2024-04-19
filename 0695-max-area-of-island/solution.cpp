class Solution {
public:
    vector<int> dir = {0, -1, 0, 1, 0};
    int dfs(vector<vector<int>>& grid, int i, int j) {
        grid[i][j] = 0;

        int ans = 0;

        for(int d=0; d<4; d++) {
            int dx = dir[d]+i;
            int dy = dir[d+1]+j;

            if(dx >= 0 && dx < grid.size() && dy >= 0 and dy < grid[0].size() and grid[dx][dy] == 1) {
                ans += 1 + dfs(grid, dx, dy);
            }
        }

        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int cnt = 0;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] != 0) {
                    cnt = max(cnt, 1 + dfs(grid, i, j));
                }
            }
        }

        return cnt;
    }
};
