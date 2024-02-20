class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x1 = 0;
        int x2 = 0;

        int n = nums.size();

        for(int i=0; i<n; i++) {
            x1 = x1 ^ nums[i];
            x2 = x2 ^ i;
        }
        x2 = x2 ^ n;

        return x1 ^ x2;
    }
};
