# Sorting The Sentence

## Leetcode Link: [Sorting The Sentence](https://leetcode.com/problems/sorting-the-sentence/)
### Language: Python

```py
class Solution:
    def sortSentence(self, s: str) -> str:
        l = s.split();
        for i in range(len(l)):
            l[i] = l[i][::-1]
        l.sort()
        for i in range(len(l)):
            l[i] = l[i][::-1]
            l[i]=l[i][:-1]
        return " ".join(l)```



