class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx = 0;

        for(auto i: nums) {
            mx |= i;
        }

        int ans = 0;

        for(int i=0; i<pow(2, nums.size()); i++) {
            int curr = 0;

            for(int j=0; j<nums.size(); j++) {
                if(i & (1 << j)) {
                    curr |= nums[j];
                }
            }

            if(curr == mx) {
                ans++;
            }
        }

        return ans;
    }
};
