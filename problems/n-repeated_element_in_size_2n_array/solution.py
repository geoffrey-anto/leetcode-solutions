class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        lt = {}
        n=int(len(nums)/2);
        for i in nums:
            if i in lt:
                lt[i]+=1;
            else:
                lt[i] = 1;           
            if lt[i] == n:
                return i;
        return -1;