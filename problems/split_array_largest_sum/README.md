# Split Array Largest Sum

## Leetcode Link: [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/)
### Language: C++

```cpp
class Solution {
    bool isPossible(vector<int>& arr, int n, int k, int curMin) {
        int res = 1;
        int curSum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > curMin) {
                return false;
            }

            if (curSum + arr[i] > curMin) {
                res += 1;

                curSum = arr[i];

                if (res > k) {
                    return false;
                }
            }
            else {
                curSum += arr[i];
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;

        for(int i=0;i<nums.size();++i) l=max(l,nums[i]), r+=nums[i];


        while (l<r) {
            int m = (l+r)/2;

            if (isPossible(nums, nums.size(), k, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return l;
    }
};```



