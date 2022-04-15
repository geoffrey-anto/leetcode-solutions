class Solution {
public:
    
    int f(int i, int j, vector<vector<int>>& nums, vector<vector<int>>& dp){
        if(i==0 and j==0) return nums[0][0];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = 1e9;
        int left = 1e9;
        
        if(i>0) up = nums[i][j] + f(i+1, j, nums, dp);
        if(j>0) left = nums[i][j] + f(i, j+1, nums, dp);
        
        return dp[i][j] = min(up, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();        
        vector<int> prev(m, 0);
        for(int i=0; i<n; i++){
            vector<int> curr(m, 0);
            for(int j=0; j<m; j++){
                if(i==0 and j==0){
                    curr[j] = grid[0][0];
                    continue;
                }
                int down = INT_MAX;
                int right = INT_MAX;
                
                if(i>0) down = prev[j];
                if(j>0) right = curr[j-1];
                
                curr[j] = grid[i][j] +  min(down, right);
            }
            prev=curr;
        }
        return prev[m-1];
    }
};
