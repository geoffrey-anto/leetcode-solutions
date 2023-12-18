# Search In Rotated Sorted Array Ii

## Leetcode Link: [Search In Rotated Sorted Array Ii](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)
### Language: C++

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return find(nums.begin(),nums.end(),target)!=nums.end()?true:false;
    }
};```



# Search In Rotated Sorted Array Ii

## Leetcode Link: [Search In Rotated Sorted Array Ii](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)
### Language: GoLang

```go
func search(nums []int, target int) bool {
    l := 0
    r := len(nums) - 1

    for l<=r {
        m := (l+r) / 2
        
        if nums[m] == target {
            return true;
        }

        if nums[l] == nums[m] {
            l++
            continue
        }


        if nums[l] <= nums[m] {
            // left half is sorted
            if nums[l] <= target && target < nums[m] {
                r = m - 1
            } else {
                l = m + 1
            }
        } else {
            // right half is sorted
            if nums[m] < target && target <= nums[r] {
                l = m + 1
            } else {
                r = m - 1
            }
        }
    }

    return false
}```



