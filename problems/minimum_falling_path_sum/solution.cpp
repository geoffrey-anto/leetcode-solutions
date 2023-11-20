class Solution {
public:
    int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int upLeft = 1e8;
        if(j>0) upLeft = matrix[i][j]+f(i-1, j-1, matrix, dp);
        
        int upRight = 1e8;
        if(j<matrix[0].size()-1) upRight = matrix[i][j]+f(i-1,j+1, matrix, dp);
        
        int up = matrix[i][j]+f(i-1,j,matrix, dp);
        
        return dp[i][j] = min(up, min(upLeft, upRight));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mn = 1e8;
        int n = matrix.size();
        int m = matrix[0].size();
        // for(int i=0;i<m;i++){
        //     vector<vector<int>> dp(n, vector<int>(m, -1));
        //     mn = min(mn, f(n-1, i, matrix, dp));
        // }
        
        vector<int> prev(m ,0);
        vector<int> curr(m, 0);
    
        for(int i=0;i<m;i++) prev[i]=matrix[0][i];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int upLeft = matrix[i][j];
                if(j-1>=0) upLeft+=prev[j-1];
                else upLeft = 1e8;

                int upRight = matrix[i][j];
                if(j+1<=m-1) upRight+=prev[j+1];
                else upRight = 1e8;

                int up = matrix[i][j]+prev[j];

                curr[j] = min(up, min(upLeft, upRight));
            }
            prev=curr;
        }
        for(int c=0; c<m;c++){
            mn = min(mn, prev[c]);
        }
        
        return mn;
    }
};