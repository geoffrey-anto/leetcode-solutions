class Solution {
public:
    int dp[40];
    
    int helper(int n){
        if(n<=1){
            return n; 
        }
        if(n==2){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=helper(n-1)+helper(n-2)+helper(n-3);
    }
    
    int tribonacci(int n) {
        memset(&dp,-1,sizeof(dp));
        return helper(n);
    }
};