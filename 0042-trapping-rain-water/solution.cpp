class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }

        int n = height.size();

        stack<int> st;
        int ans = 0;
        for(int i=0; i<n;i++) {
            while(!st.empty() && height[i] > height[st.top()]) {
                int rightMaxIdx = st.top();
                st.pop();

                if (st.empty()) {
                    break;
                }

                int leftMaxIdx = st.top();

                int x = min(height[i], height[leftMaxIdx]) - height[rightMaxIdx];
                int y = i - leftMaxIdx - 1;

                ans += (x * y);
            }

            st.push(i);
        }

        return ans;
    }
};
