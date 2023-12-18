# Move Zeroes

## Leetcode Link: [Move Zeroes](https://leetcode.com/problems/move-zeroes/)
### Language: C++

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int prev=0;
        for(int &i:nums){
            if(i!=0){
                swap(nums[prev],i);
                prev++;
            }
        }
    }

};```



