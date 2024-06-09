class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp = {{0, 1}};
        int n = nums.size();
        int curr = 0;

        int ans = 0;

        for(int i=0; i<n; i++) {
            // ?? 
            curr = (curr + nums[i] % k + k) % k;
            int rem = curr % k;

            ans += mp[curr];
            mp[curr]++;
        }

        return ans;
    }
};
