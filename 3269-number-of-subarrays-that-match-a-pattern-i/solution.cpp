class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        int ans = 0;
        
        for(int i=0; i<n-m; i++) {
            bool flag = true;
            for(int k=0; k<m; k++) {
                if(pattern[k] == 0) {
                    if(nums[i+k] != nums[i+k+1]) {
                        flag = false;
                        break;
                    }
                } else if(pattern[k] == 1) {
                    if(nums[i+k] >= nums[i+k+1]) {
                        flag = false;
                        break;
                    }
                } else {
                    if(nums[i+k] <= nums[i+k+1]) {
                        flag = false;
                        break;
                    }
                }
            }
            
            if(flag) {
                ans++;
            }
        }
        
        return ans;
    }
};
