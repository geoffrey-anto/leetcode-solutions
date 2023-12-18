# Find Greatest Common Divisor Of Array

## Leetcode Link: [Find Greatest Common Divisor Of Array](https://leetcode.com/problems/find-greatest-common-divisor-of-array/)
### Language: Python

```py
class Solution:
    def findGCD(self, nums: List[int]) -> int:
        min_=min(nums)
        max_=max(nums)
        GCD=0
        for i in range(1,min_+1):
            if min_%i==0 and max_%i==0:
                GCD=i
        return GCD```



