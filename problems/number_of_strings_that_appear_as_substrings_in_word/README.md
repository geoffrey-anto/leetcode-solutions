# Number Of Strings That Appear As Substrings In Word

## Leetcode Link: [Number Of Strings That Appear As Substrings In Word](https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/)
### Language: Python

```py
class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        c=0
        for pattern in patterns:
            for i in range(len(word)-len(pattern)+1):
                if word[i:i+len(pattern)] == pattern:
                    c+=1
                    break
                
        return c```



