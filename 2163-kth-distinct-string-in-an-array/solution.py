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

        return ''
