class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        ans=[]
        for i in range(len(boxes)):
            size=0
            for j in range(len(boxes)):
                if boxes[j]=="1":
                    size=size+abs(i-j)
            ans.append(size)
        return ans
