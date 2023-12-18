# Maximum Sum Circular Subarray

## Leetcode Link: [Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/)
### Language: C++

```cpp
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int max_sum=INT_MIN;
        int min_sum=INT_MAX;
        int arrSum=0;
        int tempMax=0;
        int tempMin=0;
        for(int i=0;i<n;i++){
            arrSum+=nums[i];
            //
            tempMax+=nums[i];
            max_sum=max_sum<tempMax ? tempMax:max_sum;
            tempMax=tempMax<0?0:tempMax;
            
            tempMin+=nums[i];
            min_sum=min_sum>tempMin ? tempMin:min_sum;
            tempMin=tempMin>0?0:tempMin;
        }
        if(arrSum==min_sum){
            return max_sum;
        } else {
            return max(max_sum,(arrSum-min_sum));
        }
    }
};```



