class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        vector<vector<int>> precompute(grid.size()+1, vector<int> (grid[0].size()+1, 0));
        
        for(int i=1; i<=grid.size(); i++) {
            for(int j=1; j<=grid[0].size(); j++) {
                precompute[i][j] = grid[i-1][j-1] + precompute[i-1][j] + precompute[i][j-1] - precompute[i-1][j-1];
            }
        }
        
        int cnt = 0;
        
        for(int i=1; i<=grid.size(); i++) {
            for(int j=1; j<=grid[0].size(); j++) {
                if(precompute[i][j] <= k) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};
