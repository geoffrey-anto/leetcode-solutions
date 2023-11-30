class Solution {
public:
    
    int findNumberOfLIS(vector<int>& nums) {
        const int n = nums.size();
        vector<int> dp(n,1), mp(n,1);
        int mx = 1;  
		
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){

					if(dp[j]+1 == dp[i]){ 
                        mp[i] += mp[j];
                    } else if(dp[j] + 1 > dp[i]){ 
                        dp[i] = dp[j] + 1;
                        mp[i] = mp[j];
                    } 
                }
            }

            mx = max(mx,dp[i]);
        }
        
        int ans = 0;

        for(int i=0;i<n;i++){
            if(dp[i]==mx) {
                ans += mp[i];
            }
        }
            
        return ans;
    }
};