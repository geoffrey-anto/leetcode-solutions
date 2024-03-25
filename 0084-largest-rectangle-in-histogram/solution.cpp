class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        const int n = arr.size();
        stack<int> st;

        vector<int> nextMin(n, -1);
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() and arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(!st.empty()) {
                nextMin[i] = st.top();
            } 

            st.push(i);

        }

        st = stack<int>();

        vector<int> prevLess(n, -1);

        for(int i=0; i<n; i++) {
            while(!st.empty() and arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(!st.empty()) {
                prevLess[i] = st.top();
            }

            st.push(i);
        }

        // now we have the nextLess and prevLess

        // so now we can compare at every index idx with these values
        int mx = 0;
        for(int i=0; i<n; i++) {
            int curr = arr[i];

            int x = (nextMin[i] == -1 ? n : nextMin[i]) - prevLess[i] - 1;

            mx = max(mx, x * curr); 
        }

    
        return mx;
    }
};
