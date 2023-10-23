class Solution {
public:
    
    int dp[100];
    
    int f(int i){
        if(i==0) return dp[i] = 1;
        if(i==1) return dp[i] = 1;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = f(i-1) + f(i-2);
    }
    
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return f(n);
    }
};