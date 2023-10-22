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
                // right is the prev point
                int rightMaxIdx = st.top();
                st.pop();

                // check if there is a left idx
                if (st.empty()) {
                    break;
                }

                int leftMaxIdx = st.top();

                // either take the curr height or the left one whichever is MIN
                int x = min(height[i], height[leftMaxIdx]) - height[rightMaxIdx];
                // find the width
                int y = i - leftMaxIdx - 1;

                // accumulate answer
                ans += (x * y);
            }

            st.push(i);
        }

        return ans;
    }
};
