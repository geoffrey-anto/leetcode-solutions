# Next Greater Element I

## Leetcode Link: [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)
### Language: C++

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int m = nums1.size();
        int n = nums2.size();
        st.push(nums2[n-1]);
        vector<int> ans(m,-1);

        unordered_map<int, int> mp;


        for(int i=n-2; i>=0; i--) {
            while(!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }

            if(!st.empty()) {
                if (i < n) {
                    mp[nums2[i]] = st.top();
                }
            }

            st.push(nums2[i]);
        }
        for(int i=0; i<m; i++) {
            if(mp[nums1[i]] != 0) {
                ans[i] = mp[nums1[i]];
            }
        }

        return ans;
    }
};```



