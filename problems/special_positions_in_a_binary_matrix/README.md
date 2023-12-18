# Special Positions In A Binary Matrix

## Leetcode Link: [Special Positions In A Binary Matrix](https://leetcode.com/problems/special-positions-in-a-binary-matrix/)
### Language: C++

```cpp
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;
        int m = mat.size();
        int n = mat[0].size();

        vector<int> r(m, 0);
        vector<int> c(n, 0);
        
        for (auto i = 0; i < m; i++) {
            for (auto j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    r[i]++;
                    c[j]++;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 and r[i] == 1 and c[j] == 1) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};```



