# Reverse Words In A String Iii

## Leetcode Link: [Reverse Words In A String Iii](https://leetcode.com/problems/reverse-words-in-a-string-iii/)
### Language: Python

```py
class Solution:
    def reverseWords(self, s: str) -> str:
        s=s+" "
        ans=""
        temp = ""
        for idx,i in enumerate(s):
            if i == ' ':
                temp=temp[::-1]
                ans=ans+" "+ temp
                temp=""
            else:
                temp+=i
        return ans[1:]```



