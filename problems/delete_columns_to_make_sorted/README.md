# Delete Columns To Make Sorted

## Leetcode Link: [Delete Columns To Make Sorted](https://leetcode.com/problems/delete-columns-to-make-sorted/)
### Language: Python

```py
class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        cnt=0
        for i in range(len(strs[0])):
            for j in range(len(strs)-1):
                if ord(strs[j][i]) > ord(strs[j+1][i]):
                    cnt+=1;
                    break;
        return cnt;```



