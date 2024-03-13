class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++) {
            if(count(begin(grid[i]), end(grid[i]), 0) == 1) {
                return i;
            }
        }

        return -1;
    }
};
