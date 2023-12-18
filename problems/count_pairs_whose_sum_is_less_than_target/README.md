# Count Pairs Whose Sum Is Less Than Target

## Leetcode Link: [Count Pairs Whose Sum Is Less Than Target](https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/)
### Language: C++

```cpp
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int cnt = 0;
        int n = nums.size();
        
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i] + nums[j] < target) {
                    cnt++;
                } 
            }
        }
        return cnt;
    }
};```



