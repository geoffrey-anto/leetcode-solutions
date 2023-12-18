# Longest Repeating Character Replacement

## Leetcode Link: [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)
### Language: C++

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> map;

        int curr = 0;
        int prev = 0;

        int mx = 0;
        int ans = 0;

        // move curr by one if the window has atmost k non eq elements
        // it it has more reduce the value in map and inc. prev ptr
        // so we get the size of window as CURR - PREV
        // so take the max among them
        for(curr = 0; curr < n; curr++) {
            map[s[curr]]++;
            mx = max(mx, map[s[curr]]);
                        
            // mx -> count of elements which are same
            // so if window size - count > k it has more duplicate values
            while(curr - prev - mx + 1 > k) {
                map[s[prev]]--;
                prev++;
            }

            ans = max(ans, curr - prev + 1);
        }

        return ans;
    }
};```



