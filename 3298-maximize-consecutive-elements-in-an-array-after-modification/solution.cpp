class Solution {
public:
    vector<unordered_map<int, int>> dp;
    vector<int> num;
    
    int f(int i, int prev, int n) {
        if(i == n) {
            return 0;
        } 
        
        // we have prev value with us eg: 2
        // we have to use maybe take or not take to find 
        // opt1: not take and move to i+1
        // opt2: take the curr and move to i+1
        // opt3: take the curr+1 and move to i+1
        // take max;
        
        if(dp[i].find(prev) != dp[i].end()) {
            return dp[i][prev];
        }
        
        int ans = 0;
        
        if(prev + 1 == num[i] + 1) {
            ans = max(ans, 1 + f(i+1, num[i]+1, n));
        } 

        if(prev + 1 == num[i]) {
            ans = max(ans, 1 + f(i+1, num[i], n));
        }

        if (num[i] + 1 == prev) {
            ans = max(ans, f(i + 1, num[i] + 1, n));
        }
        
        return dp[i][prev] = ans;
    }
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        if(n == 1) {
            return 1;
        }
        
        dp = vector<unordered_map<int, int>>(n);
        
        int ans = 0;
        
        num = nums;
        
        for(int i=0; i<n; i++) {
            ans = max(ans, 1 + f(i+1, nums[i], n));
            ans = max(ans, 1 + f(i+1, nums[i]+1, n));
        }
        
        return ans;
    }
};
