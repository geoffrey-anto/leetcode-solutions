class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        mx = 0
        l=[]
        l=[i.count('1') for i in bank if i.count('1') != 0]
        if len(l) == 1:
            return 0;
        else:
            mx=0
            for i in range(len(l)-1):
                mx=mx+l[i]*l[i+1]
            return mx
        return -1
