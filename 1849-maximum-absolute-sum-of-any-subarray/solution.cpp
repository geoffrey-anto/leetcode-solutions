class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // we can run kadane twice; one for max and one for min
        // then return max(abs(a), abs(b))

        int a = nums[0];
        int curr_a = nums[0];

        for (int i=1; i<nums.size(); i++) {
            curr_a = max(curr_a + nums[i], nums[i]);
            a = max(a, curr_a);
        }
        

        int b = nums[0];
        int curr_b = nums[0];

        for (int i=1; i<nums.size(); i++) {
            curr_b = min(curr_b + nums[i], nums[i]);
            b = min(b, curr_b);
        }

        return max(abs(a), abs(b));
    }
};
