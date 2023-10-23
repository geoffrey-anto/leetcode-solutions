class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>dp(mx+1,0);
        vector<int>freq(mx+1,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]] ++;
        }
        dp[1]=freq[1];
        dp[2]=max(dp[1],freq[2]*2);
        for(int i=3;i<=mx;i++){
            dp[i]=max(dp[i-1],i*freq[i]+dp[i-2]);
        }
        return dp[mx];
    }
};