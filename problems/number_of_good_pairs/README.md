# Number Of Good Pairs

## Leetcode Link: [Number Of Good Pairs](https://leetcode.com/problems/number-of-good-pairs/)
### Language: C++

```cpp
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> map;
        for(auto i:nums){
            map[i]++;
        }
        for(auto [i,c]:map){
            ans=ans+(c*(c-1))/2;
        }
        return ans;
    }
};```



# Number Of Good Pairs

## Leetcode Link: [Number Of Good Pairs](https://leetcode.com/problems/number-of-good-pairs/)
### Language: Python

```py
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
        return int(ans)```



