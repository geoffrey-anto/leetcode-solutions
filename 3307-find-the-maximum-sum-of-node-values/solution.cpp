class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<int> delta(nums.size(), 0);

        for(int i=0; i<nums.size(); i++) {
            delta[i] = (nums[i] ^ k) - nums[i];
        }

        sort(begin(delta), end(delta), greater<int>());

        long long res = accumulate(begin(nums), end(nums), 0ll);

        for(int i=0; i<nums.size(); i+=2) {
            if(i == nums.size()-1) {
                break;
            }

            long long pd = delta[i] + delta[i+1];

            if(pd <= 0ll) {
                break;
            }

            res += pd;
        }

        return res;
    }
};
