# Largest Odd Number In String

## Leetcode Link: [Largest Odd Number In String](https://leetcode.com/problems/largest-odd-number-in-string/)
### Language: C++

```cpp
class Solution {
public:
    string largestOddNumber(string num) {
        int p = num.length()-1;

        while(p >= 0 && (num[p] - '0') % 2 == 0) {
            p--;
        }

        return p<0 ? "" : num.substr(0,p+1);
    }
};```



