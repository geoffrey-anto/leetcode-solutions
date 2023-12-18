# Minimum Number Of Days To Make M Bouquets

## Leetcode Link: [Minimum Number Of Days To Make M Bouquets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)
### Language: GoLang

```go
func isPossible(bloomDay []int, m int, k int, idx int) bool {
    cnt := 0

    for _, v := range bloomDay {
        if v <= idx {
            cnt++;

            if cnt == k {
                cnt = 0;
                m--;
            }
        } else {
            cnt = 0;
        }
    }

    return m<=0;
}

func minDays(bloomDay []int, m int, k int) int {
    n := len(bloomDay)

    if m * k > n {
        return -1
    } 

    min := 1000_000_001
    max := 0

    for _, v := range bloomDay {
        if v < min {
            min = v
        }

        if v > max {
            max = v
        }
    }

    left, right := min, max
    
    for left <= right {
        x := (left + right) / 2

        if (isPossible(bloomDay, m, k, x)) {
            right = x - 1;
        } else {
            left = x + 1;
        }

    }

    return left
}```



