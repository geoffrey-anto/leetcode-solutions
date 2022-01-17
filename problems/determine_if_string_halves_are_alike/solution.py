class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        n=len(s)
        mid = int(n/2)
        l=('a','e','i','o','u','A','E','I','O','U')
        lc=0
        rc=0
        for i in list(l):
            lc+=s[:mid].count(i)
        for i in list(l):
            rc+=s[mid:].count(i)
        return lc==rc
            