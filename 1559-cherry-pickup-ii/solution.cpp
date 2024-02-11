class Solution {
public:
    int f(int i, int j1, int j2, vector<vector<int>>& grid, int c, int r, vector<vector<vector<int>>> &dp){
        if(i==r-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        
        int mx=0;

        for(int x1=-1; x1<2; x1++){
            for(int x2=-1; x2<2; x2++){
                if(j1+x1<0 or j2+x2<0 or j1+x1>=c or j2+x2 >= c) continue;

                int value=0;
                if(j1==j2) value = grid[i][j1];
                else value = grid[i][j1]+grid[i][j2];

                value+=f(i+1, j1+x1, j2+x2, grid, c, r, dp);
                mx=max(mx, value);
            }
        }
        return dp[i][j1][j2] = mx;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c,-1)));
        
        return f(0, 0, c-1, grid, c, r, dp);
    }
};
