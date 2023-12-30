class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> mp;

        for(auto &w: words) {
            for(auto &c: w) {
                mp[c]++;
            }
        }   

        int n = words.size();

        for(auto &[key, val]: mp) {
            if(val % n != 0) {
                return false;
            }
        }

        return true;
    }
};
