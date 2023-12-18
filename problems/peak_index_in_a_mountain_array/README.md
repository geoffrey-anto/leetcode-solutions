# Peak Index In A Mountain Array

## Leetcode Link: [Peak Index In A Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/)
### Language: C++

```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0;
        while (arr[i] < arr[i+1]) i++;
        return i;
    }
};```



