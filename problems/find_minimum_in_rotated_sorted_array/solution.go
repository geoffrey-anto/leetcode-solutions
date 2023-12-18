func findMin(nums []int) int {
    l := 0
    h := len(nums) - 1

    ans := 10000

    for l<=h {
        m := (l+h) / 2

        if nums[l] <= nums[h] {
            if nums[l] <= ans {
                ans = nums[l]
                break
            }
        }

        if nums[l] <= nums[m] {
            if nums[l] <= ans {
                ans = nums[l]
            }

            l = m + 1
        } else {
            if nums[m] <= ans {
                ans = nums[m]
            }
            h = m - 1
        }
    }

    return ans
}