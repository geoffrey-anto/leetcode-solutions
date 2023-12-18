# Longest Substring Without Repeating Characters

## Leetcode Link: [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
### Language: C++

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
        int mx = 0;
        int prev = 0;
        
        for (int i = 0; i < n; i++) {
            char curr = s[i];
            // check if it already in map
            if (mp.find(s[i]) == mp.end() || mp[s[i]] < prev) {
                // if not there take the max between last found idx and curr idx
                mx = max(mx, i - prev + 1);
            } else {
                // else if there update the prev
                prev = mp[s[i]] + 1;
            }
            // store the val in map
            mp[s[i]] = i;
        }
        
        return mx;
    }
};```



