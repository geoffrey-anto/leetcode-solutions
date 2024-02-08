# Largest Substring Between Two Equal Characters

## Leetcode Link: [Largest Substring Between Two Equal Characters](https://leetcode.com/problems/largest-substring-between-two-equal-characters/)
### Language: C++

```cpp
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size(), ans = 0;

        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(s[i] == s[j]) {
                    ans = max(ans, j - i);
                }
            }
        }

        return ans - 1;
    }
};```



