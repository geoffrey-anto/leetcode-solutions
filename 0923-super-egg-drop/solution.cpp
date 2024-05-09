// class Solution {
// public:
//     int f(int k, int i, int n, vector<vector<int>> &dp) {
//         if(i == 0) {
//             return i;
//         }

//         if(i == 1) {
//             return i;
//         }

//         if(k == 1) {
//             return i;
//         }

//         if(dp[k][i] != -1) {
//             return dp[k][i];
//         }

//         int ans = INT_MAX;

//         for(int j=1; j<=i; j++) {
//             int c1 = f(k-1, j-1, n, dp);
//             int c2 = f(k, i - j, n, dp);

//             int temp = 1 + max(c1, c2);

//             ans = min(ans, temp);
//         }

//         return dp[k][i] = ans;
//     }

//     int superEggDrop(int k, int n) {
//         vector<vector<int>> dp(k+1, vector<int> (n+1, -1));

//         return f(k, n, n, dp);
//     }
// };

// TF

class Solution {
public:
    int f(int k, int n, vector<vector<int>> &dp) {
        if(n == 0) {
            return n;
        }

        if(n == 1) {
            return n;
        }

        if(k == 1) {
            return n;
        }

        if(dp[k][n] != -1) {
            return dp[k][n];
        }

        int ans = INT_MAX;
        int l = 0;
        int r = n;
        
        while(l <= r){
            int mid = l + (r - l) / 2;
            
            int c1 = f(k-1, mid-1, dp);
            int c2 = f(k, n-mid, dp);
            
            int temp = 1 + max(c1, c2);
            
            if(c1 < c2) 
                l = mid+1;
            else 
                r = mid-1;
    
            ans = min(ans, temp); 
        }

        return dp[k][n] = ans;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1, vector<int> (n+1, -1));

        return f(k, n, dp);
    }
};
