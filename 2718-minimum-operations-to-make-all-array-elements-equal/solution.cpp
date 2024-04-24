class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        vector<long long> pre(n, 0);

        for(int i=0; i<n; i++) {
            if(i == 0) {
                pre[i] = (long long)nums[i];
            } else {
                pre[i] = pre[i-1] + (long long)nums[i];
            }
        }

        // for(auto i: nums) {
        //     cout << i << " ";
        // }
        // cout << endl;

        vector<long long> res;


        for(long long i: queries) {
            auto it = lower_bound(begin(nums), end(nums), i);

            long long pos = it - nums.begin();

            // cout << pos << endl;

            long long rmax = (n - pos) * i;

            long long lmax = (pos - 0) * i;

            // cout << lmax << " " << rmax << endl;

            long long ans = 0ll;

            if(pos == n) {
                long long lCurr = pre[n-1]; 

                long long rCurr = 0;

                ans = abs(lmax - lCurr) + abs(rmax - rCurr);

                // cout << ans << endl;
            } else {
                long long lCurr = pre[pos] - nums[pos]; 

                long long rCurr = pre[n-1] - pre[pos] + nums[pos];

                ans = abs(lmax - lCurr) + abs(rmax - rCurr);

                // cout << ans << endl;
            }

            res.push_back(ans);

        }

        return res;
    }
};
