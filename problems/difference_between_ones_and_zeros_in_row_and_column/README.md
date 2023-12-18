# Difference Between Ones And Zeros In Row And Column

## Leetcode Link: [Difference Between Ones And Zeros In Row And Column](https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/)
### Language: C++

```cpp
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> onesRow(n, 0);
        vector<int> onesCol(m, 0);

        for(int i=0; i<n; i++) {
            int cnt = 0;
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1) {
                    cnt++;
                }
            }
            onesRow[i]=cnt;
        }

        for(int i=0; i<m; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(grid[j][i]==1) {
                    cnt++;
                }
            }
            onesCol[i]=cnt;
        }

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans[i][j] = onesRow[i]*2 + onesCol[j]*2 - n - m;
            }
        }

        return ans;
    }
};```



