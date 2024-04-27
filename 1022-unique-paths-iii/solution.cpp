class Solution {
public:
    vector<vector<bool>> vis;
    int ans = 0;
    void f(int x, int y, int m, int n, vector<vector<int>>& nums, int ei, int ej, int cnt, int c = 0) {
        if(x >= m  or y >= n or x < 0 or y < 0 or nums[x][y] == -1) {
            return;
        }

        if(vis[x][y]) return;

        if(nums[x][y] == 2) {
            if(c == cnt) {
                ans++;
            }
            return;
        }


        vis[x][y] = true;
        f(x+1, y, m, n, nums, ei, ej, cnt ,c+1);
        f(x, y+1, m, n, nums, ei, ej, cnt ,c+1);
        f(x-1, y, m, n, nums, ei, ej, cnt ,c+1);
        f(x, y-1, m, n, nums, ei, ej, cnt ,c+1);
        vis[x][y] = false;

        return;
    }
        
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ei = 0, ej = 0, si = 0, sj = 0;

        int cnt = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    si = i;
                    sj = j;
                } else if(grid[i][j] == 2) {
                    ei = i;
                    ej = j;
                } else if(grid[i][j] == 0){
                    cnt++;
                }
            }
        }

        vis = vector<vector<bool>>(n+1, vector<bool>(m+1, false));
        f(si, sj, n, m, grid, ei, ej, cnt+1);

        return ans;
    }
};
