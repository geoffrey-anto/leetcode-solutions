class Solution {
public:
    bool f(int idx, vector<int> &nums, int sum, vector<vector<int>> &dp){
        if(sum == 0) return true;
        if(idx == 0) return (sum == nums[0]);
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        bool notpick = f(idx-1, nums, sum, dp);
        bool pick = false;
        if(sum>=nums[idx]) pick = f(idx-1, nums, sum-nums[idx], dp);
        
        dp[idx][sum] = (pick or notpick);
        return (pick or notpick);
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(auto &i: nums){
            sum+=i;
        }
        vector<bool> prev(sum+1, false);
        
        if(sum%2!=0){
            return false;
        } else {
            vector<bool> curr(sum+1, false);
            sum=sum/2;
            int target=sum;
            prev[0] = true;
            curr[0] = true;
            for(int idx=1;idx<n;idx++){
                
                for(int sum=1; sum<=target; sum++){
                    bool notpick = prev[sum];
                    bool pick = false;
                    if(sum>=nums[idx]){
                        pick = prev[sum-nums[idx]];
                    }

                    curr[sum] = (pick or notpick);
                }
                prev=curr;
            }
            return prev[target];
        }
        return false;
    }
};