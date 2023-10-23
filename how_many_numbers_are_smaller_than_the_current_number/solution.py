class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        ans=[]
        for idx,i in enumerate(nums):
            temp=0
            for jidx,j in enumerate(nums):
                if(j<i and idx!=jidx):
                    temp+=1
            ans.append(temp)
        return ans