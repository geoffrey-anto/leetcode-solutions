# Minimum Number Of Steps To Make Two Strings Anagram

## Leetcode Link: [Minimum Number Of Steps To Make Two Strings Anagram](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/)
### Language: C++

```cpp
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> m1;

        for(auto &i: s) {
            m1[i]++;
        }

        for(auto &i: t) {
            m1[i]--;
        }

        int ans = 0;

        for(auto &[k, v]: m1) {
            if(v > 0) {
                ans += v;
            }
        }

        return ans;
    }
};```



