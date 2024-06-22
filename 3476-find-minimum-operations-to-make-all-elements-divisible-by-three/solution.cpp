class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++) {
            int rem = nums[i] % 3;
            
            ans += min(rem, 3 - rem);
        }
        
        return ans;
    }
};
