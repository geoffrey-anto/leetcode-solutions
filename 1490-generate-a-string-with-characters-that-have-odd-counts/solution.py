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
        
