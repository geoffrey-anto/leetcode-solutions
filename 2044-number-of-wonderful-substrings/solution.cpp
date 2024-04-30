class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int runningMask = 0;
        unordered_map<int, int> mp; mp[0] = 1;
        long long ans = 0;

        for(auto i: word) {
            runningMask = runningMask ^ (1 << (i-'a'));

            if(mp.count(runningMask) > 0) {
                ans += (long long)(mp[runningMask]);
                mp[runningMask]++;
            } else {
                mp[runningMask] = 1;
            }

            for(int j=0; j<11; j++) {
                int m = runningMask ^ (1 << j);
                if(mp.count(m) > 0) {
                    ans += mp[m];
                }
            }
        }

        return ans;
    }
};
