# Check If Array Is Sorted And Rotated

## Leetcode Link: [Check If Array Is Sorted And Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/)
### Language: C++

```cpp
class Solution {
public:
    bool check(vector<int>& nums) {
        int k=0;
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<=nums[i+1] )
            {
                k++;
            }         
        }
        if(k==n-2 && nums[0]>=nums[n-1])
        {
            return true;
        }
        else if(k==n-1)
        {
            return true;
        }
        else
            return false;
    }
};```



# Check If Array Is Sorted And Rotated

## Leetcode Link: [Check If Array Is Sorted And Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/)
### Language: GoLang

```go
func check(nums []int) bool {
    if len(nums) == 1{
        return true;
    }
    
    left := nums[0];
    right := nums[len(nums) - 1];
    
    c := 0;
    
    for i:=0; i<len(nums) - 1; i++ {
        if nums[i] <= nums[i+1] {
            c++;
        }
    }

    if (c == len(nums)-2) && (left >= right) {
        return true;
    } else if( c==len(nums)-1) {
        return true;
    }
    
    return false;
}```



