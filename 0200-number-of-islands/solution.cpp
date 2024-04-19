class Solution {
public:
    vector<int> dir = {0, -1, 0, 1, 0};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';

        for(int d=0; d<4; d++) {
            int dx = dir[d]+i;
            int dy = dir[d+1]+j;

            if(dx >= 0 && dx < grid.size() && dy >= 0 and dy < grid[0].size() and grid[dx][dy] == '1') {
                dfs(grid, dx, dy);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] != '0') {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
