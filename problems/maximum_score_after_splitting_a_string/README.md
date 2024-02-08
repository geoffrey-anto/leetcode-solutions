# Maximum Score After Splitting A String

## Leetcode Link: [Maximum Score After Splitting A String](https://leetcode.com/problems/maximum-score-after-splitting-a-string/)
### Language: C++

```cpp
class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int pos = 0;

        int lc = 0;
        int rc = 0;

        for(int i=0; i<n; i++) {
            if(s[i] == '1') {
                rc++;
            }
        }

        int mx = 0;

        for(int i=0; i<n-1; i++) {
            if(s[i] == '0') {
                lc++;
            } else {
                rc--;
            }
            mx = max(mx, lc+rc);
        }

        return mx;
    }
};```



