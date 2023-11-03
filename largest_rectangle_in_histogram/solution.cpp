class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        const int n = arr.size();
        stack<int> st;

        st.push(-1);
        vector<int> nextMin(n);
        for(int i=n-1; i>=0; i--) {
            while(st.top() != -1 and arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(!st.empty()) {
                nextMin[i] = st.top();
                st.push(i);
            } else {
                nextMin[i] = arr[i];
                st.push(arr[i]);
            }

        }

        st = stack<int>();

        st.push(-1);
        vector<int> prevLess(n);

        for(int i=0; i<n; i++) {
            while(st.top() != -1 and arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(!st.empty()) {
                prevLess[i] = st.top();
                st.push(i);
            } else {
                prevLess[i] = arr[i];
                st.push(arr[i]);
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