# Koko Eating Bananas

## Leetcode Link: [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)
### Language: GoLang

```go
func minEatingSpeed(piles []int, h int) int {
    left, right := 1, 0
    
    for i, e := range piles {
     if i==0 || e > right {
         right = e
     }
    }


    for left < right {
        mid := (left + right) / 2
        hours := 0
        
        for _, pile := range(piles) {
            hours += int(math.Ceil(float64(pile) / float64(mid)))
        }
        
        if hours <= h {
            right = mid
        } else {
            left = mid + 1
        }
    }
    return right

}```



