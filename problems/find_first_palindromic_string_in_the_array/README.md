# Find First Palindromic String In The Array

## Leetcode Link: [Find First Palindromic String In The Array](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/)
### Language: Python

```py
class Solution:    
    def firstPalindrome(self, words: List[str]) -> str:
        for i in words:
            if i==i[::-1]:
                return i
        return ""```



