class Solution {
public:
    int f(int i, int sum, int t, vector<int>& nums, int n, map<pair<int, int>, int> &mp) {
        if(i == n) {
            return sum == t ? 1 : 0;
        }

        auto x = mp.find(make_pair(i, sum));
        if(x != mp.end()) {
            return (*x).second;
        }

        int plus = f(i+1, sum+nums[i], t, nums, n, mp);
        int minus = f(i+1, sum-nums[i], t, nums, n, mp);

        return mp[make_pair(i, sum)] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<pair<int, int>, int> mp;
        return f(0, 0, target, nums, n, mp);
    }
};
