class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto &i: s) {
            mp[i]++;
        }

        sort(begin(s), end(s), [&](auto &a, auto &b) {
            if(mp[a] == mp[b]) {
                return a < b;
            }

            return mp[a] > mp[b];
        });

        return s;
    }
};
