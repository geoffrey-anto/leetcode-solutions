# Find The Difference

## Leetcode Link: [Find The Difference](https://leetcode.com/problems/find-the-difference/)
### Language: Python

```py
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        c = 0
        for cs in s: c ^= ord(cs) #ord is ASCII value
        for ct in t: c ^= ord(ct)
        return chr(c) #chr = convert ASCII into character```



