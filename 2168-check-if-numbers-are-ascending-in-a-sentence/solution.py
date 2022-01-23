class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        s=s.split()
        prev = -1
        flg=True
        idxx = -1
        for idx,i in enumerate(s):
            if i.isdigit():
                prev=int(i);
                idxx=idx
                break
        for idx,i in enumerate(s):
            if i.isdigit():
                if prev>=int(i) and idx!=idxx:
                    flg = False
                prev=int(i)
        return flg;
                
