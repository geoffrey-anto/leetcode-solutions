class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> preMax, sufMax;

        int mx = 0;

        for(auto i: nums) {
            mx = max(mx, i);
            preMax.push_back(mx);
        }

        mx = 0;

        for(int i=nums.size()-1; i>=0; i--) {
            mx = max(mx, nums[i]);
            sufMax.push_back(mx);
        }

        reverse(begin(sufMax), end(sufMax));

        long long ans = 0ll;

        for(auto i=1; i<nums.size()-1; i++) {
            long long curr = (long long)(preMax[i-1] - nums[i]) * (long long)sufMax[i+1];
            if(curr < 0) {
                continue;
            }

            ans = max(ans, curr);
        }

        return ans;
    }
};
