# N Repeated Element In Size 2N Array

## Leetcode Link: [N Repeated Element In Size 2N Array](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/)
### Language: C++

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> map;
        int n=nums.size();
        n=n/2;
        for(auto &i:nums){
            map[i]++;
            if(map[i] >= n){
                return i;
            }
        }
        return -1;
    }
};```



# N Repeated Element In Size 2N Array

## Leetcode Link: [N Repeated Element In Size 2N Array](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/)
### Language: Python

```py
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
        return -1;```



