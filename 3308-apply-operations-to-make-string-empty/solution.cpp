class Solution {
public:
    string lastNonEmptyString(string s) {
        map<char, int> mp;
        int n = s.size();
        
        int mx = 0;
        
        for(auto &i: s) {
            mp[i]++;
            mx = max(mx, mp[i]);
        }
        
        string ans = "";
        
        vector<int> vis(26, 0);
        
        for(int i=n-1; i>=0; i--) {
            char c = s[i];
            if(mp[c] == mx && !vis[c - 'a']) {
                ans = c + ans;
                vis[c - 'a'] = 1;
            }
        }
        
        return ans;
    }
};
