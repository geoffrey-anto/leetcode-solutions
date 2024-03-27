class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int curr = 0;
        int prev = 0;

        unordered_map<char, int> mp;

        int ans = 0;

        for(int i=0; i<s.size(); i++) {
            char curr = s[i];

            if(mp.find(curr) == mp.end() or mp[s[i]] < prev) {
                ans = max(ans, (i - prev + 1));
            } else {
                prev = mp[curr] + 1;
            }

            mp[curr] = i;
        }

        return ans;
    }
};
