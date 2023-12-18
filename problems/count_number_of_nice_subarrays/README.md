# Count Number Of Nice Subarrays

## Leetcode Link: [Count Number Of Nice Subarrays](https://leetcode.com/problems/count-number-of-nice-subarrays/)
### Language: C++

```cpp
class Solution {
public:
    bool isOdd(int n) {
        return (n % 2) != 0;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int prev = 0;
        int curr = 0;
        int mx1 = 0;
        int cnt = 0;

        int n = nums.size();
        
        for(curr = 0; curr < n; curr++) {
            if(isOdd(nums[curr])) {
                cnt++;
            }

            while (cnt > k) {
                if(isOdd(nums[prev])) {
                    cnt--;
                }
                prev++;
            }

            mx1 += (curr - prev + 1);
        }

        if(k==0) {
            return mx1;
        }

        prev = 0;
        curr = 0;
        int mx2 = 0;
        cnt = 0;
        
        for(curr = 0; curr < n; curr++) {
            if(isOdd(nums[curr])) {
                cnt++;
            }

            while (cnt > (k-1)) {
                if(isOdd(nums[prev])) {
                    cnt--;
                }
                prev++;
            }

            mx2 += (curr - prev + 1);
        }

        return mx1 - mx2;
    }
};```



