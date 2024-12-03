class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";

        unordered_map<int, bool> mp;

        for(auto i: spaces) {
            mp[i] = true;
        }

        for(int i=0; i<s.size(); i++) {
            if(mp[i]) {
                ans += " ";
                ans += s[i];
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};
