class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        lt = []
        for i in range(len(s)):
            lt.append(1000000)
        p1 = -1
        for i in range(len(s)):
            if s[i] == c:
                p1 = i
            if p1 != -1:
                lt[i] = abs(i-p1);
        p1 = -1;
        for i in range(len(s)-1,-1,-1):
            if s[i] == c:
                p1 = i;
            if p1 != -1:
                lt[i]  = min(abs(p1-i),lt[i])
        return lt;
