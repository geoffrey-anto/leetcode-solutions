class Solution {
public:
    vector<int> dir = {0, -1, 0, 1, 0};
    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    bool isPossible(vector<vector<int>>& grid, int t) {

        if(t < grid[0][0]) {
            return false;
        }

        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int, int>> q;

        vector<vector<bool>> vis(grid.size(), vector<bool> (grid[0].size(), false));

        q.push({0, 0});

        while(!q.empty()) {
            auto top = q.top();
            q.pop();
            vis[top.first][top.second] = true;

            if(top.first == n-1 && top.second == m-1) {
                return true;
            }

            for(int d=0; d<4; d++) {
                int nx = top.first + dir[d];
                int ny = top.second + dir[d+1];

                if(isValid(nx, ny, n, m) && grid[nx][ny] <= t && !vis[nx][ny]) {
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
    bool valid(vector<vector<int>>& grid, int t) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<int> dir({-1, 0, 1, 0, -1});
        return dfs(grid, vis, dir, t, 0, 0, n);
    }
    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, vector<int>& dir, int t, int row, int col, int n) {
        vis[row][col] = 1;
        for (int i = 0; i < 4; ++i) {
            int r = row + dir[i], c = col + dir[i+1];
            if (r >= 0 && r < n && c >= 0 && c < n && vis[r][c] == 0 && grid[r][c] <= t) {
                if (r == n-1 && c == n-1) return true;
                if (dfs(grid, vis, dir, t, r, c, n)) return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();


        int l = grid[0][0];
        int r = n*n - 1;

        int ans = 0;

        while(l<=r) {
            int m = l + ((r - l) / 2);

            if(valid(grid, m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }
};
