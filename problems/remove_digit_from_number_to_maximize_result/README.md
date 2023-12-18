# Remove Digit From Number To Maximize Result

## Leetcode Link: [Remove Digit From Number To Maximize Result](https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/)
### Language: GoLang

```go
func removeDigit(number string, digit byte) string {
    idx := 0
    n := len(number)
    
    for i:=0; i<n; i++ {
        if digit == number[i] {
            idx = i
            if i+1 < n && number[i] < number[i+1] {
				break
			}
        }
    }
    
    return number[:idx] + number[idx+1:]
}```



