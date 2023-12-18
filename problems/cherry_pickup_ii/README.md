# Cherry Pickup Ii

## Leetcode Link: [Cherry Pickup Ii](https://leetcode.com/problems/cherry-pickup-ii/)
### Language: C++

```cpp
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<int>> prev(c, vector<int> (c, 0));
        
        for(int j1=0;j1<c;j1++){
            for(int j2=0; j2<c; j2++){
                if(j1==j2) prev[j1][j2] = grid[r-1][j1];
                else prev[j1][j2] = grid[r-1][j1]+grid[r-1][j2];
            }
        }
        
        for(int i=r-2; i>=0; i--){
            vector<vector<int>> curr(c, vector<int> (c, 0));
            for(int j1=0; j1<c; j1++){
                for(int j2=0; j2<c; j2++){
                    int mx=-1e8;

                    for(int x1=-1; x1<2; x1++){
                        for(int x2=-1; x2<2; x2++){
                            int value=0;
                            if(j1==j2) value = grid[i][j1];
                            else value = grid[i][j1]+grid[i][j2];
                            if(j1+x1>=0 and j2+x2>=0 and j1+x1<c and j2+x2<c)
                                value+=prev[j1+x1][j2+x2];
                            else
                                value+= -1e8;
                            mx=max(mx, value);
                        }
                    }
                    curr[j1][j2] = mx;
                }
            }
            prev=curr;
        }
        
        return prev[0][c-1];
    }
};```



