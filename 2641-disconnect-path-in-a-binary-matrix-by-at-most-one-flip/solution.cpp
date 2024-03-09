class Solution {
public:
    bool f(int i, int j, int n, int m, vector<vector<int>> &grid) {
        if(i == n && j == m) {
            return true;
        }

        grid[i][j] = 0;


        int ans = 0;

        if(i < n && grid[i+1][j] == 1) {
            if(f(i+1, j, n, m, grid)) return true;
        }

        if(j < m && grid[i][j+1] == 1) {
            if(f(i, j+1, n, m, grid)) {
                return true;
            }
        }

        return false;
    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(f(0, 0, n-1, m-1, grid) == false) return true;
        if(f(0, 0, n-1, m-1, grid) == false) return true;

        return 0;
    }
};
