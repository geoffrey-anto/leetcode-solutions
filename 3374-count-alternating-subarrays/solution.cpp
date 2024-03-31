class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int ones = 0;
        
        ones = accumulate(begin(nums), end(nums), 0);
        
        int n = nums.size();
                
        long long ans = 0;
        int l = 0;
        int r = 0;

        while (r < n) {
            while (r < n - 1 && nums[r] != nums[r + 1]) {
                r++;
            }

            long long len = r - l + 1;

            ans += (len * (len + 1ll)) / 2ll;

            l = r = r + 1;
        }

        return ans;
    }
};
