// E O E O E  O  E
// 3,3,7,7,10,11,11

// IF E O then right else if O E then left
func singleNonDuplicate(nums []int) int {
    n := len(nums)

    if n == 1 {
        return nums[0]
    }

    if nums[0] != nums[1] {
        return nums[0];
    }

    if nums[n-1] != nums[n-2] {
        return nums[n-1]
    }

    l := 1

    r := len(nums) - 2

    for l<=r {
        m := (l+r)/2

        if nums[m-1] != nums[m] && nums[m] != nums[m+1] {
            return nums[m]
        }

        // if E & O and same                  or E & O and same        SO IN RIGHT
        if (m%2 == 1 && nums[m] == nums[m-1]) || (m%2 == 0 && nums[m] == nums[m+1]) {
            l = m + 1
        } else {
            r = m - 1
        }
    }

    return -1
}