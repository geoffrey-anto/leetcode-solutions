class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        long long sum = accumulate(begin(nums), end(nums), 0ll);
        sort(begin(nums), end(nums));

        int prev = nums[0];

        int ans = 0;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] <= nums[i-1] + 1) {
                nums[i] = nums[i-1]+1;
            }
        }

        return accumulate(begin(nums), end(nums), 0ll) - sum;
    }
};
