#define ll long long

class Solution {
public:
    ll f(int i, int prev, ll diff, vector<int>& nums, int n, map<pair<ll, ll>, ll> &dp) {
        if(i == n) {
            return 0;
        }

        auto x = dp.find({prev, diff});

        if(x != dp.end()) {
            return (*x).second;
        }

        ll tot = 0;

        for(int curr=i; curr<n; curr++) {
            if((ll)((ll)nums[curr] - (ll)nums[prev]) == diff) {
                tot += (1ll + f(curr+1, curr, diff, nums, n, dp));
            }
        }

        return dp[{prev, diff}] = tot;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        map<pair<ll, ll>, ll> dp;

        ll ans = 0ll;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                ans = ans + (ll)(f(j+1, j, (ll)nums[j] - nums[i], nums, n, dp));
            }
        }

        return ans;
    }
};
