class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }

        int n = nums.size();

        int x = 0;

        for(int mask=0; mask<(1<<n); mask++) {
            int curr = 0;

            for(int i=0; i<n; i++) {
                if(((1 << i) & mask) != 0) {
                    curr ^= nums[i];
                }
            }

            x += curr;
        }

        return x;
    }
};
