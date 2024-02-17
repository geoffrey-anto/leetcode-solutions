class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int sum = nums[0] + nums[1];
        int n = nums.size();
        
        int ans = 1;
        
        for(int i=2; i<n; i+=2) {
            if(i+1 < n) {
                if(nums[i] + nums[i+1] == sum) {
                    ans ++;
                } else {
                    break;
                }
            } else {
                break;
            }
        }
        
        return ans;
    }
};
