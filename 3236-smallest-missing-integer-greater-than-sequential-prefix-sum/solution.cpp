class Solution {
public:
    
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        
        int currSum = nums[0];
        
        int ans = -1;
        
        for(int i=1; i<n; i++) {
            if(nums[i] == (nums[i-1] + 1)) {
                currSum += nums[i];
            } else {
                break;
            }
        }
        
        ans = currSum;
        
        // cout << ans << endl;
        
        if(find(begin(nums), end(nums), ans) == nums.end()) {
            return ans;
        } else {
            for(int i=ans+1; i<=*max_element(begin(nums), end(nums))+1; i++) {
                if(find(begin(nums), end(nums), i) == nums.end()) {
                    return i;
                }
            }
        }
        
        return -1;
    }
};
