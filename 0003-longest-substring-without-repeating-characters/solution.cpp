class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;

        int ans = 0;

        int l = 0;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;

            while(l < i and mp[s[i]] >= 2) {
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};
