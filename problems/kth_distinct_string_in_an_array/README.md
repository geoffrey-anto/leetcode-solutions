# Kth Distinct String In An Array

## Leetcode Link: [Kth Distinct String In An Array](https://leetcode.com/problems/kth-distinct-string-in-an-array/)
### Language: Python

```py
from collections import Counter
from typing import List
class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        c = Counter(arr)
        for e in arr:
            if c[e] == 1:
                if k == 1:
                    return e
                k -= 1

        return ''```



