class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        d = {}
        for i in nums:
            if i not in d:
                d[i] = 1
            else:
                d[i]+=1;
        ans=0
        for i in d.keys():
            ans += (d[i]*(d[i]-1))/2 
        return int(ans)