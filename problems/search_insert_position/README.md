# Search Insert Position

## Leetcode Link: [Search Insert Position](https://leetcode.com/problems/search-insert-position/)
### Language: C++

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int n = nums.size();
        int h = n-1;
        int idx = 0;
        int m = -1;
        while(l<=h) {
            m =  l+ h-l/ 2;

            if(nums[m] == target) {
                return m;
            } else if(nums[m] > target) {
                h = m-1;
            } else {
                l = m+1;
            }
        }
        if(nums[m] < target) {
            return m+1;
        }

        if(m==0) {
            return 0;
        }

        return m-1;
    }

};
```



