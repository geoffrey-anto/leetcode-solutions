class Solution {
public:
    int dp[1010];
    // int helper(int n,vector<int> v){
    //     if(n==0){
    //         return dp[n]=v[n];
    //     }
    //     if(n==1){
    //         return dp[n]=v[n];
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     return dp[n]=v[n]+min(helper(n+1,v),helper(n+2,v));
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(&dp,-1,sizeof(dp));
        int n=cost.size();
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        return min(dp[n-1],dp[n-2]);
    }
};