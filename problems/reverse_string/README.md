# Reverse String

## Leetcode Link: [Reverse String](https://leetcode.com/problems/reverse-string/)
### Language: Python

```py
class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        mid=int(len(s)/2)
        for i in range(mid):
            temp = s[i]
            s[i]=s[len(s)-1-i]
            s[len(s)-1-i]=temp```



