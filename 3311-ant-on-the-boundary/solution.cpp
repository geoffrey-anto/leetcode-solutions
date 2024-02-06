class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int ans = 0;
        
        int curr = 0;
        
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            if(nums[i] < 0) {
                curr += nums[i];
            } else {
                curr += nums[i];
            }
            
            if(curr == 0) {
                ans++;
            }
        }
        
        return ans;
    }
};
