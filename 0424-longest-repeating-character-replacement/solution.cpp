class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;

        int ans = 0;

        int l = 0, m = 0;

        for(int i=0; i<n; i++) {
            mp[s[i]] ++;

            m = max(m, mp[s[i]]);

            while(l < i and i - l + 1 - m > k) {
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, i - l + 1);
        }

        return ans;
    }
};
