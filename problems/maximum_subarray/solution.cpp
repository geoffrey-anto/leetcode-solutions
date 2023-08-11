class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax = 0;
        int overalMax = INT_MIN;
        for(auto &i: nums) {
            currMax = max(currMax+i, i);
            overalMax = max(overalMax, currMax);
        }
        return overalMax;
    }
};