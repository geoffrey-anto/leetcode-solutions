# Number Of Islands

## Leetcode Link: [Number Of Islands](https://leetcode.com/problems/number-of-islands/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    void dfs(int i, int j, vector<vector<char>>& grid, int n, int m) {
        grid[i][j] = '0';

        for(int d=0; d<4; d++) {
            int nx = i + dir[d];
            int ny = j + dir[d+1];

            if(isValid(nx, ny, n, m) && grid[nx][ny] == '1') {
                dfs(nx, ny, grid, n, m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    dfs(i, j, grid, n, m);
                    cnt++;
                }
            }
        }

        return cnt;
    } 
};```



