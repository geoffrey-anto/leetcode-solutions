# Remove K Digits

## Leetcode Link: [Remove K Digits](https://leetcode.com/problems/remove-k-digits/)
### Language: C++

```cpp
class Solution {
public:
    // Stack + ans string -> vector + toString -> only string functions (C++)
    string removeKdigits(string num, int k) {
        string st;
        int n = num.length();

        int k_copy = k;

        if(k==0) return num;

        if(n <= k) {
            return "0";
        }

        st.push_back(num[0]);

        for(auto i=1; i<n; i++) {
            while(k > 0 && st.size() != 0 && st[st.length()-1] > num[i]) {
                k--;
                st.pop_back();
            }

            st.push_back(num[i]);

            if(st.length() == 1 && num[i] == '0'){
                st.pop_back();
            }
        }

        if(k!=0) {
            // more are there
            while(k > 0 && st.length() != 0) {
                st.pop_back();
                k--;
            }

        }

        if(st.length() == 0) {
            return "0";
        }

        return st;

    }
};```



