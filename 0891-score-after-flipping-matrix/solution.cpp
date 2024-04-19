class Solution {
public:
    void toggleRow(vector<int> &row) {
        for(auto &i: row) {
            i = !i;
        }
    }

    void toggleCol(int c, vector<vector<int>>& grid) {
        int m = grid.size();

        for(int i=0; i<m; i++) {
            grid[i][c] = !grid[i][c];
        }
    }

    int sumCol(int c, vector<vector<int>>& grid) {
        int m = grid.size();
        int ans = 0;
        for(int i=0; i<m; i++) {
            ans += grid[i][c];
        }

        return ans;
    }

    int getVal(vector<int> &row) {
        int ans = 0;

        for(auto i: row) {
            ans = (ans << 1) | i;
        }

        return ans;
    }

    int matrixScore(vector<vector<int>>& grid) {
        for(auto &i: grid) {
            if(i[0] != 1) {
                toggleRow(i);
            }
        }

        for(int i=0; i<grid[0].size(); i++) {
            int s = sumCol(i, grid);

            if(s <= grid.size()/2) {
                toggleCol(i, grid);
            }
        }

        int ans = 0;

        for(auto &i: grid) {
            ans += getVal(i);
        }

        return ans;
    }
};
