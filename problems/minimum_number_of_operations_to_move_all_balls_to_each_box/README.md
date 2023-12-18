# Minimum Number Of Operations To Move All Balls To Each Box

## Leetcode Link: [Minimum Number Of Operations To Move All Balls To Each Box](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(boxes[j]=='1'){
                    sum+=abs(j-i);
                }
            }
            ans.push_back(sum);

        }
        return ans;
    }
};```



# Minimum Number Of Operations To Move All Balls To Each Box

## Leetcode Link: [Minimum Number Of Operations To Move All Balls To Each Box](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/)
### Language: Python

```py
class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        ans=[]
        for i in range(len(boxes)):
            size=0
            for j in range(len(boxes)):
                if boxes[j]=="1":
                    size=size+abs(i-j)
            ans.append(size)
        return ans```



