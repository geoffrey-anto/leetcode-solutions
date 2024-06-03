class Solution {
public:
    string getMaxNum(vector<int> &nums, int k) {
        stack<int> st;

        for(int i=0; i<nums.size(); i++) {
            while(!st.empty() && nums[i] > nums[st.top()] and nums.size() - i + st.size() > k) {
                st.pop();
            }

            if(st.size() < k)
                st.push(i);
        }

        string ans;

        while(!st.empty() && k) {
            ans += to_string(nums[st.top()]);
            st.pop();
            k--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    string largestMerge(string v1, string v2) {
        if (v1.size() == 0  || v2.size() == 0)
            return v1 + v2;
        if (v1 > v2)
            return v1[0] + largestMerge(v1.substr(1), v2);
        return v2[0] + largestMerge(v1, v2.substr(1));
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        string ans;

        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                if(i + j == k) {
                    string mx1 = getMaxNum(nums1, i);
                    string mx2 = getMaxNum(nums2, j);

                    string mx = largestMerge(mx1, mx2);

                    if(mx > ans) {
                        ans = mx;
                    }
                }
            }
        }

        vector<int> res;

        for(auto i: ans) {
            res.push_back(i - '0');
        }

        return res;
    }
};
