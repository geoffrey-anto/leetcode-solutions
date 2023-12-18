# Remove Outermost Parentheses

## Leetcode Link: [Remove Outermost Parentheses](https://leetcode.com/problems/remove-outermost-parentheses/)
### Language: C++

```cpp
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";

        int no = 0;

        for(auto &i :s) {
            if (i == '(') {
                if(no > 0) {
                    ans += i;
                }
                no++;
            } else {
                if ( no > 1 ) {
                    ans += i;
                }
                no--;
            }
        }
        return ans;
    }
};```



