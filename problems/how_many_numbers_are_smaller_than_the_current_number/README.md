# How Many Numbers Are Smaller Than The Current Number

## Leetcode Link: [How Many Numbers Are Smaller Than The Current Number](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      unordered_map<int, int> m;
      vector<int> new_nums(nums);
      int n = nums.size();
      
      sort(new_nums.begin(), new_nums.end());
      
      for (int i = n - 1; i >= 0; --i) {
        m[new_nums[i]] = i;
      }
      
      for (int i = 0; i < n; ++i) {
        nums[i] = m[nums[i]];
      }
      return nums;
    }
};

```



# How Many Numbers Are Smaller Than The Current Number

## Leetcode Link: [How Many Numbers Are Smaller Than The Current Number](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/)
### Language: Python

```py
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        ans=[]
        for idx,i in enumerate(nums):
            temp=0
            for jidx,j in enumerate(nums):
                if(j<i and idx!=jidx):
                    temp+=1
            ans.append(temp)
        return ans```



