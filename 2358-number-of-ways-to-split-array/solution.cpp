class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        long long pre = 0ll;

        for(auto i: nums) {
            pre += (long long)i;
        }

        long long curr = (long long)nums[0];

        int ans = 0;

        for(int i=1; i<n; i++) {
            long long left = pre - curr;

            if(curr >= left) {
                ans++;
            }


            curr = curr + (long long) nums[i];
        }

        return ans;
    }
};
