class Solution {
public:
    int longestAwesome(string s) {
        int runningMask = 0;
        vector<int> mp(1024, s.size());
        mp[0] = -1;

        int ans = 0;
        int x = 0;

        for(auto i: s) {
            runningMask = runningMask ^ (1 << (i-'0'));

            for(int j=0; j<10; j++) {
                int m = runningMask ^ (1 << j);
                int r = mp[m];

                ans = max(x - r, ans);
            }

            ans = max(ans, x - mp[runningMask]);
            mp[runningMask] = min(mp[runningMask], x);
            x++;
        }

        return ans;
    }
};
