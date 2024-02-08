# Plus One

## Leetcode Link: [Plus One](https://leetcode.com/problems/plus-one/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> ans;
        int carry=1;
        for(int i=n-1;i>=0;i--){
            if(carry!=0){
                int x=(digits[i]+carry)%10;
                carry=(digits[i]+carry)/10;
                ans.push_back(x);
            } else {
                ans.push_back(digits[i]);
            }
        }
        if(carry!=0){
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};```



# Plus One

## Leetcode Link: [Plus One](https://leetcode.com/problems/plus-one/)
### Language: Java

```java
class Solution {
    public int[] plusOne(int[] d) {
        int n = d.length;

        int carry = 0;

        if(d[n-1] + 1 > 9) {
            carry = 1;
            d[n-1] = 0;
        } else {
            d[n-1]++;
        }    

        for(int i=n-2; i>=0; i--) {
            if(carry == 1) {
                if(d[i] + 1 > 9) {
                    d[i] = 0;
                    carry = 1;
                } else {
                    d[i]++;
                    carry = 0;
                }
            } else {
                break;
            }
        }

        if(carry == 1) {
            int[] arr = new int[n+1];
            for(int i=0; i<n; i++) {
                arr[i+1] = d[i];
            }
            arr[0] = 1;

            return arr;
        }

        return d;
    }
}```



