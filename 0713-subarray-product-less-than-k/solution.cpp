class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;

        int prod = 1;
        int ans = 0;

        while(r < nums.size()) {
            prod = prod * nums[r];

            while(l <= r) {
                if(prod < k) {
                    break;
                }
                prod = prod / nums[l];
                l++;
            }

            ans += (r - l + 1);
            r++;
        }

        return ans;
    }
};
