class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        vector<int> ans(n, -1);
        vector<int> res;

        unordered_map<int, int> ref;

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums2[st.top()] < nums2[i]) {
                st.pop();
            }

            if(!st.empty()) {
                ans[i] = nums2[st.top()];
            }

            st.push(i);
            ref[nums2[i]] = i;
        }


        for(auto i: nums1) {
            res.push_back(ans[ref[i]]);
        }

        return res;
    }
};
