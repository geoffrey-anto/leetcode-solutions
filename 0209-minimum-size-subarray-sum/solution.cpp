class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;

        int l = 0;
        int r = 0;

        int currentSum = 0;

        for(r=0; r<nums.size(); r++) {
            currentSum += nums[r];

            while(currentSum >= target) {
                int sizeOfSubarray = r - l + 1;
                ans = min(ans, sizeOfSubarray);
                currentSum -= nums[l];
                l++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
