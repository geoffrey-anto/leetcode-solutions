# Minimum Changes To Make Alternating Binary String

## Leetcode Link: [Minimum Changes To Make Alternating Binary String](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/)
### Language: C++

```cpp
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        bool isOne = false;
        int cnt1 = 0;
        // 0 start
        for(int i=0; i<n; i++) {
            if(isOne) {
                if(s[i] == '1') {
                    cnt1++;
                }
            } else {
                if(s[i] == '0') {
                    cnt1++;
                }
            }
            isOne = !isOne;
        }
        // 1 start
        isOne = true;
        int cnt2 = 0;
        for(int i=0; i<n; i++) {
            if(isOne) {
                if(s[i] == '1') {
                    cnt2++;
                }
            } else {
                if(s[i] == '0') {
                    cnt2++;
                }
            }
            isOne = !isOne;
        }

        return min(cnt1, cnt2);
    }
};```



