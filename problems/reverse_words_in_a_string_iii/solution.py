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
        return ans[1:]