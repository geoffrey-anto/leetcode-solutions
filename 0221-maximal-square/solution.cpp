class Solution {
public:

    int helper(vector<vector<char>>& matrix, int i, int j, int row, int col, int &maxi, vector<vector<int>> &dp){
        if(i >= row || j >= col){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j]; 

        int right = helper(matrix, i , j + 1, row, col, maxi, dp);
        int diagonal = helper(matrix, i + 1, j + 1, row, col, maxi, dp);
        int down = helper(matrix, i + 1, j, row, col, maxi, dp);

        if(matrix[i][j] == '1'){
            int ans = 1 + min(right, min(down, diagonal));
            maxi = max(maxi, ans);
            return dp[i][j] = ans;
        } else{
            return 0;
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1)); 
        int maxi = 0;
        int ans = helper(matrix, 0, 0, matrix.size(), matrix[0].size(), maxi, dp);
        return maxi*maxi;
        
    }
};
