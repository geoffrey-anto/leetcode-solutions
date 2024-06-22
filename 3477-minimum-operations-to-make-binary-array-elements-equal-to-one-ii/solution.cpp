class Solution {
public:
        int minOperations(vector<int>& nums) {
        // maybe bitset?
        // 
        
        int n = nums.size();
        bitset<100001> b;
        
        for (int i = 0; i < n; ++i) {
            if(nums[i]) {
                b.set(i);
            }
        }
        
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (b.test(i) == 0) {
                ans++;
                b = ~b;
            }
        }

        return ans;
    }
};
