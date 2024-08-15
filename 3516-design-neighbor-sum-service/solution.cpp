class NeighborSum {
public:
    unordered_map<int, pair<int, int>> mp;
    
    NeighborSum(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                int val = grid[i][j];

                int adj = 0;
                int diag = 0;

                if(i-1 >= 0) {
                    adj += grid[i-1][j];
                    if(j-1 >= 0)
                        diag += grid[i-1][j-1];
                    if(j+1 < grid.size())
                        diag += grid[i-1][j+1];
                }

                if(i+1 < grid.size()) {
                    adj += grid[i+1][j];
                    if(j-1 >= 0)
                        diag += grid[i+1][j-1];
                    if(j+1 < grid.size())
                        diag += grid[i+1][j+1];
                }
                
                if(j-1 >= 0) {
                    adj += grid[i][j-1];
                }

                if(j+1 < grid.size()) {
                    adj += grid[i][j+1];
                }

                mp[val] = {adj, diag};
            }
        }
    }
    
    int adjacentSum(int value) {
        return mp[value].first;
    }
    
    int diagonalSum(int value) {
        return mp[value].second;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
