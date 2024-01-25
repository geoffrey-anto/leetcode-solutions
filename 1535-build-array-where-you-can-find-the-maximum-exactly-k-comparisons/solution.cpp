class Solution {
public:
    const unsigned int MOD = 1000000007;

    int dp[52][52][102];

    int f(int n, int m, int k, int currMax) {
        // If we have filled all the elements
        if(n == 0) {
            // If the search cost is equal to 0
            if(k == 0) {
                // We found a way
                return 1;
            }

            // We didnt find a way
            return 0;
        }

        // If we have exhausted the search cost, we havent found a way to arrange the array
        if(k == -1) {
            return 0;
        }

        if(dp[n][k][currMax] != -1) {
            return dp[n][k][currMax];
        }

        long long ans = 0;

        // Go over through all the available values which can be used at Nth position in array
        for(int i=1; i<=m; i++) {

            // if we found a new global max in the array it implies that there is a aditional cost 
            // for finding the maximum using the given algorithm
            // Eg:
            //  Given Array  10,  2,  3, 12,  5,  6
            //  Current Max  10, 10, 10, 12, 12, 12
            //  Search Cost   1,  1,  1,  2,  2,  2
            // So search cost is incremented when we find a new max element
            // So when we find a new max element we reduce K by 1
            if(i > currMax) {
                // pass the current new max element as the currMax value
                ans += f(n-1, m, k-1, i);
            } else {
                ans += f(n-1, m, k, currMax);
            }
        }

        // Do a mod to stay within int limits
        return dp[n][k][currMax] = ans%MOD;
    }

    int numOfArrays(int n, int m, int k) {
        // Initialize dp array to -1
        memset(dp, -1, sizeof(dp));

        return f(n, m, k, 0);
    }
};
