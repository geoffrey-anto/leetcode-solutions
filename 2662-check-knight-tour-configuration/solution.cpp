class Solution {
public:
    vector<vector<int>> dir = {
        {2, 1},
        {2, -1},
        {-2, 1},
        {-2, -1},
        {1, 2},
        {-1, 2},
        {1, -2},
        {-1, -2},
    };
    bool f(int i, int j, vector<vector<int>>& grid, int n) {
        bool ans = false;

        if(grid[i][j] == (n*n) - 1) {
            return true;
        }

        for(int d=0; d<dir.size(); d++) {
            int dx = i + dir[d][0];
            int dy = j + dir[d][1];

            if(dx >= 0 and dx < n and dy >= 0 and dy < n) {
                if(grid[i][j] + 1 == grid[dx][dy]) {
                    ans = ans or f(dx, dy, grid, n);
                }
            }
        }

        return ans;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int i = 0, j = 0;
        int n = grid.size();

        if(grid[i][j] != 0) {
            return false;
        }

        return f(i, j, grid, n);
    }
};
