# Truncate Sentence

## Leetcode Link: [Truncate Sentence](https://leetcode.com/problems/truncate-sentence/)
### Language: Python

```py
class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        return " ".join(s.split()[:k])```



