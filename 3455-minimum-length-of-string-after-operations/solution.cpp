class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;

        for(auto i: s) {
            mp[i]++;
        }

        int ans = 0;

        for(auto &[k, v]: mp) {
            if(v == 0)
                continue;
            else if(v % 2 == 0)
                ans += (2);
            else
                ans += (v % 2);
        }

        return ans;
    }
};
