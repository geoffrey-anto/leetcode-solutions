class Solution {
public:
    int MOD = 1e9 + 7;
    // Easy But Modulo Fucked up
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> mp;

        long long ans = 0;

        for(int i=0; i<hours.size(); i++) {
            int hmod = hours[i] % 24ll;

            int mod = (24ll - hmod) % 24ll;

            int cnt = mp[mod];

            ans = (ans + cnt);
            
            mp[hmod]++;
        }

        return ans;
    }
};
