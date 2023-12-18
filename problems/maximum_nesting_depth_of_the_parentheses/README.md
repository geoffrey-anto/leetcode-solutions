# Maximum Nesting Depth Of The Parentheses

## Leetcode Link: [Maximum Nesting Depth Of The Parentheses](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/)
### Language: C++

```cpp
class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int mxCnt = 0;
        for(auto &i: s) {
            if (i != '(' and i != ')') {
                continue;
            } else {
                if (i == '(') {
                    cnt++;
                } else {
                    cnt--;
                }
                mxCnt = max(mxCnt, cnt);
            }
        }

        return mxCnt;
    }
};```



# Maximum Nesting Depth Of The Parentheses

## Leetcode Link: [Maximum Nesting Depth Of The Parentheses](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/)
### Language: Python

```py
class Solution:
    def maxDepth(self, s: str) -> int:
        ans = cur = 0
        for c in s:
            if c == '(':
                cur += 1
                ans = max(ans, cur)
            elif c == ')':
                cur -= 1
        return ans ```



