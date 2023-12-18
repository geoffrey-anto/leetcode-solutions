# Jewels And Stones

## Leetcode Link: [Jewels And Stones](https://leetcode.com/problems/jewels-and-stones/)
### Language: Python

```py
class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        c=0
        for i in jewels:
            c+=stones.count(i)
        return c```



