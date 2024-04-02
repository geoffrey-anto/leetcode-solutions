class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, bool> vis;

        for(int i=0; i<s.size(); i++) {
            if(mp.find(t[i]) == mp.end() && !vis[s[i]]) {
                mp[t[i]] = s[i];
                vis[s[i]] = true;
            } else {
                if(mp[t[i]] != s[i]) {
                    return false;
                } else {
                    continue;
                }
            }
        }

        return true;
    }
};
