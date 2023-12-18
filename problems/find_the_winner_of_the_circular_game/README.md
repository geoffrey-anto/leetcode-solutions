# Find The Winner Of The Circular Game

## Leetcode Link: [Find The Winner Of The Circular Game](https://leetcode.com/problems/find-the-winner-of-the-circular-game/)
### Language: Python

```py
class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        curr = 0;
        l = list(range(1,n+1));
        while(len(l)!=1):
            curr=((curr+k-1)%len(l));
            l.remove(l[curr]);
        return l[0];```



