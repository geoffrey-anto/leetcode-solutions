class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i < n; i++) {
            for(int j=i+1; j<n; j++) {
                bool flg = true;
                for(int k = i+1; k <= j; k++) {
                    if(nums[k-1] >= nums[k]) {
                        flg = false;
                    }
                }
                
                bool flg2 = true;
                for(int k = i+1; k <= j; k++) {
                    if(nums[k-1] <= nums[k]) {
                        flg2 = false;
                    }
                }
                
                if(flg or flg2) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        
        if(ans == 0 and n != 0) {
            return 1;
        }
        
        return ans;
    }
};
