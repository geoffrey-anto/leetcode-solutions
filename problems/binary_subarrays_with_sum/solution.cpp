class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int prev = 0;
        int curr = 0;

        int mx = 0;

        int currSum = 0;

        for(curr = 0; curr < n; curr++) {
            currSum += nums[curr];
            while(currSum > goal) {
                currSum -= nums[prev];
                prev++;
            }

            mx += (curr - prev + 1);
        }

        if(goal == 0) {
            return mx;
        }

        prev = 0;
        curr = 0;
        int mx2 = 0;
        currSum = 0;

        for(curr = 0; curr < n; curr++) {
            currSum += nums[curr];
            while(currSum > goal - 1) {
                currSum -= nums[prev];
                prev++;
            }

            mx2 += (curr - prev + 1);
        }

        return mx - mx2;
    }
};