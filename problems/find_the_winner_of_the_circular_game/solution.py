class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        curr = 0;
        l = list(range(1,n+1));
        while(len(l)!=1):
            curr=((curr+k-1)%len(l));
            l.remove(l[curr]);
        return l[0];