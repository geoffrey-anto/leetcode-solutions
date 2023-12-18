# Max Consecutive Ones Iii

## Leetcode Link: [Max Consecutive Ones Iii](https://leetcode.com/problems/max-consecutive-ones-iii/)
### Language: C++

```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int prev = 0;
        int n = nums.size();

        int curr = 0;

        for(curr = 0; curr < n; curr++) {
            if(nums[curr] == 0) {
                k--;
            }

            // if there are more than k zeros
            if (k < 0) {
                if (nums[prev] == 0) {
                    k++;
                }
                prev++;
            }
        }

        return curr - prev;
    }
};```



