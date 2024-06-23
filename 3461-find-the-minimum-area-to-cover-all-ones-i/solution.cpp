class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int left = cols, right = 0, top = rows, bottom = 0;

        for(int i=0; i<rows; i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]) {
                    if (j < left) left = j;
                    if (j > right) right = j;
                    if (i < top) top = i;
                    if (i > bottom) bottom = i;
                }
            }
        }

        return (right - left + 1) * (bottom - top + 1);
    }
};
