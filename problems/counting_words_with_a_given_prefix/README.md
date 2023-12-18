# Counting Words With A Given Prefix

## Leetcode Link: [Counting Words With A Given Prefix](https://leetcode.com/problems/counting-words-with-a-given-prefix/)
### Language: Python

```py
class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        l = len(pref)
        c=0
        for i in range(len(words)):
            if words[i][:l] == pref:
                c+=1
        return c```



