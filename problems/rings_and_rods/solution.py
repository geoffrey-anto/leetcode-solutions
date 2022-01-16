class Solution:
    def countPoints(self, rings: str) -> int:
        n = len(rings)
        d = {
            '1':[0,0,0],
            '2':[0,0,0],
            '3':[0,0,0],
            '4':[0,0,0],
            '5':[0,0,0],
            '6':[0,0,0],
            '7':[0,0,0],
            '8':[0,0,0],
            '9':[0,0,0],
            '0':[0,0,0]
        }
        for idx,i in enumerate(rings):
            if (idx+1)%2 != 0:
                if i =='R':
                    d[rings[idx+1]][0] = 1
                if i=='G':
                    d[rings[idx+1]][1] = 1
                if i=='B':
                    d[rings[idx+1]][2] = 1
        s=0
        for i in d.keys():
            if d[i].count(0) == 0:
                s+=1;
        return s;