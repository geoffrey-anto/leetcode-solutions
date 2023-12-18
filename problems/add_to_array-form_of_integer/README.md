# Add To Array Form Of Integer

## Leetcode Link: [Add To Array Form Of Integer](https://leetcode.com/problems/add-to-array-form-of-integer/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int n=num.size();
        int carry=k;
        int i=n-1;
        while(i>=0 or carry){
            if(i>=0){
                carry+=num[i];
                i--;
            }
            ans.push_back(carry%10);
            carry/=10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};```



