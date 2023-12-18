# Determine Color Of A Chessboard Square

## Leetcode Link: [Determine Color Of A Chessboard Square](https://leetcode.com/problems/determine-color-of-a-chessboard-square/)
### Language: C++

```cpp
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        char a=coordinates[0];
        int num = coordinates[1]-'0';
        int nm = int(a)-96;
        if(num%2==0){
            if(nm%2==0){
                return false;
            } else {
                return true;
            } 
        } else {
            if(nm%2==0){
                return true;
            } else {
                return false;
            }
        }
        return true;
    }
};```



