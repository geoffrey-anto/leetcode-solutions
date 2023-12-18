# Generate A String With Characters That Have Odd Counts

## Leetcode Link: [Generate A String With Characters That Have Odd Counts](https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/)
### Language: Python

```py
class Solution:
    def generateTheString(self, n: int) -> str:
        a = 'a'
        b = 'b'
        c=''        
        if n%2 == 0:
            a=a*(n-1);
            b=b;
            c=a+b
        else:
            a=a*(n);
            c=a
        return c
        ```



