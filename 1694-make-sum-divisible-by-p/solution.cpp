class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = accumulate(begin(nums), end(nums), 0ll);

        if(sum % p == 0) {
            return 0;
        }

        int rem = sum % p;


        map<int, int> pre;

        pre[0] = -1;

        long long preSum = 0ll;

        int mn = nums.size();

        for(int i=0; i<nums.size(); i++) {
            preSum += nums[i];

            int curr = preSum % p;

            int remS = (curr - rem  + p) % p;

            if(pre.find(remS) != pre.end()) {
                mn = min(mn, i - pre[remS]);
            }

            pre[curr] = i;
        }

        return mn == nums.size() ? -1 : mn;
    }
};
