class Solution {
public:
    // Easy But Modulo Fucked up
    int countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> mp;

        int ans = 0;

        for(int i=0; i<hours.size(); i++) {
            int hmod = hours[i] % 24;

            int mod = (24 - hmod) % 24;

            int cnt = mp[mod];

            ans += cnt;

            // cout << hours[i] << " " << ans << endl;

            mp[hmod]++;
        }

        return ans;
    }
};
