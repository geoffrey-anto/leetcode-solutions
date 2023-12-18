# Array With Elements Not Equal To Average Of Neighbors

## Leetcode Link: [Array With Elements Not Equal To Average Of Neighbors](https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> arr(n);
        int x = 0;
        for(int i=0;i<n;i+=2){
            arr[i] = nums[x];
            x++;
        }
        for(int i=1;i<n;i+=2){
            arr[i] = nums[x];
            x++;
        }
        return arr;
    }
};```



