# Number Of Enclaves

## Leetcode Link: [Number Of Enclaves](https://leetcode.com/problems/number-of-enclaves/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> d = {0, 1, 0, -1, 0};
    int ans = 0;
    bool isValid(int i, int j, int n, int m) {
        return i>=0 && i<n && j>=0 && j < m;
    }
    void dfs(int i, int j, vector<vector<int>>& board) {
        if(!isValid(i, j, board.size(), board[0].size()) or board[i][j] != 1) return;

        board[i][j] = 0;

        for(int x=0; x<4; x++) {
            dfs(i+d[x], j+d[x+1], board);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<m; i++) {
            if(grid[0][i] == 1) {
                dfs(0, i, grid);
            }
            if(grid[n-1][i] == 1) {
                dfs(n-1, i, grid);
            }
        }

        for(int i=0; i<n; i++) {
            if(grid[i][0] == 1) {
                dfs(i, 0, grid);
            }
            if(grid[i][m-1] == 1) {
                dfs(i, m-1, grid);
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};```



