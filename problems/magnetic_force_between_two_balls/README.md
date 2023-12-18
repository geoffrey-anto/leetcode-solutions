# Magnetic Force Between Two Balls

## Leetcode Link: [Magnetic Force Between Two Balls](https://leetcode.com/problems/magnetic-force-between-two-balls/)
### Language: GoLang

```go
func isPossible(position []int, m int, mid int) bool {
    n := len(position)

    cnt := 1

    last := position[0]


    for i := 1; i<n; i++ {
        if position[i] - last >= mid {
            cnt++;
            last = position[i];
        }

        if cnt >= m {
            return true;
        }
    }

    return false;
}

func maxDistance(position []int, m int) int {
    sort.Ints(position);

    n := len(position)
    l := 0
    r := position[n-1] - position[0]

    for l<=r {
        mid := (l+r)/2

        if isPossible(position, m, mid) {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }

    return r;
}```



