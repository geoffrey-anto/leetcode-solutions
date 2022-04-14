// Memo
// class Solution {
// public:
    
//     int f(int i,int j, vector<vector<int>>& arr, int n, vector<vector<int>>& dp){
//         if(i==n-1){
//             return arr[n-1][j];
//         }
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int d = arr[i][j] + f(i+1, j , arr, n, dp);
//         int dg = arr[i][j] + f(i+1, j+1, arr, n, dp);
        
//         return dp[i][j] = min(d,dg);
//     }
    
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         return f(0, 0, triangle, n, dp);
//     }
// };

// Tabulation

// class Solution {
// public:
    
//     int f(int i,int j, vector<vector<int>>& arr, int n, vector<vector<int>>& dp){
//         if(i==n-1){
//             return arr[n-1][j];
//         }
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int d = arr[i][j] + f(i+1, j , arr, n, dp);
//         int dg = arr[i][j] + f(i+1, j+1, arr, n, dp);
        
//         return dp[i][j] = min(d,dg);
//     }
    
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int>(n, 0));
//         for(int i=0; i<n;i++) dp[n-1][i] = triangle[n-1][i];
//         for(int i=n-2; i>=0; i--){
//             for(int j=i; j>=0; j--){
//                 int d = triangle[i][j] + dp[i+1][j];
//                 int dg = triangle[i][j] + dp[i+1][j+1];
                
//                 dp[i][j] = min(d, dg);
//             }
//         }
//         return dp[0][0];
//     }
// };



class Solution {
public:    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n, 0);
        for(int i=0; i<n;i++) prev[i] = triangle[n-1][i];
        for(int i=n-2; i>=0; i--){
            vector<int> curr(n, 0);
            for(int j=i; j>=0; j--){
                int d = triangle[i][j] + prev[j];
                int dg = triangle[i][j] + prev[j+1];
                
                curr[j] = min(d, dg);
            }
            prev=curr;
        }
        return prev[0];
    }
};
