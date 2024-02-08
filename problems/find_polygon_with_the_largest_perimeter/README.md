# Find Polygon With The Largest Perimeter

## Leetcode Link: [Find Polygon With The Largest Perimeter](https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/)
### Language: C++

```cpp
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        long long sidesTaken = n;
        long long runningSum = 0;
        
        for(auto &i: nums) {
            runningSum += i;
        }
        
        for(int i=0; i<n; i++) {
            int i_end = n - i - 1;
            
            if((runningSum - nums[i_end]) <= nums[i_end]) {
                sidesTaken--;
                runningSum = runningSum - nums[i_end];
            }
        }
        
        return sidesTaken >= 3 ? runningSum : -1;
    }
};```



