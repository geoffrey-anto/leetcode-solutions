class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());

        int j = 0;  

        long long curr = 0ll;

        long long ans = 0ll;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == mx) {
                curr++;
            }

            while(curr >= k) {
                if(nums[j] == mx) {
                    curr--;
                }
                j++;
            }

            ans += j;
        }

        return ans;
    }
};
