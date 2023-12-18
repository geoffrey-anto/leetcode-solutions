# Find The Smallest Divisor Given A Threshold

## Leetcode Link: [Find The Smallest Divisor Given A Threshold](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/)
### Language: GoLang

```go
func isPossible(nums []int, threshold int, div int) float64 {
    sum := 0.0
    for _, v := range nums {
        sum += math.Ceil(float64(float64(v)/float64(div)));
    }
    return sum
}

func smallestDivisor(nums []int, threshold int) int {
    l := 1
    r := -1

    for i, e := range nums {
        if i==0 || e > r {
            r = e
        }
    }

    for l<= r {
        m := (l+r) / 2

        if v := isPossible(nums, threshold, m); v <= float64(threshold){
            r = m - 1
        } else {
            l = m + 1
        }
    }

    return l
}```



