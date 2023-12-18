# Pascal'S Triangle Ii

## Leetcode Link: [Pascal'S Triangle Ii](https://leetcode.com/problems/pascals-triangle-ii/)
### Language: GoLang

```go
func getRow(rowIndex int) []int {
    res := []int{1}
    prev := 1
    for k := 1; k <= rowIndex; k++ {
        next_val := prev * (rowIndex - k + 1) / k
        res = append(res, next_val)
        prev = next_val
    }
    return res

}```



