# Merge Sorted Array

## Leetcode Link: [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)
### Language: C++

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = nums1.size() - 1; // last idx
        n--;
        m--;
        while(n >= 0) {
            if(m >= 0 && nums1[m] > nums2[n]) {
                nums1[last] = nums1[m];
                m--;
                last--;
            } else {
                nums1[last] = nums2[n];
                n--;
                last--;
            }
        }
    }
};```



