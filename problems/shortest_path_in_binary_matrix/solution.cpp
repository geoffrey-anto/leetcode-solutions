class Solution {
    vector<vector<int>> D = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        queue<pair<int, int>> q;

        if(n == 0 || m == 0) {
            return -1;
        }

        if(grid[0][0] == 1 or grid[n-1][m-1] == 1) {
            return -1;
        }

        q.push({0,0});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x == n-1 && y == m-1) return grid[x][y] + 1;

            for(auto d: D) {
                int nextX = x + d[0];
                int nextY = y + d[1];

                if(isValid(nextX, nextY, n, m) && grid[nextX][nextY] == 0) {
                    q.push({nextX, nextY});

                    grid[nextX][nextY] = grid[x][y] + 1;
                }
            }
        }

        return -1;
    }
};