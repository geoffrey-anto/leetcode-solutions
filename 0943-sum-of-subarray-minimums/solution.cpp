class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prevLess(n, -1);
        stack<int> st;
        int MOD = pow(10, 9) + 7;

        for(int i=0; i<n; i++) {
            while (!st.empty() and arr[st.top()] > arr[i]) st.pop();

            if(!st.empty()) {
                prevLess[i] = st.top();
            }

            st.push(i);
        }

        vector<int> res(n, 0);

        for(int i=0; i<n; i++) {
            if (prevLess[i] == -1) {
                res[i] = (0) + (i - prevLess[i]) * arr[i];   
                continue;
            }
            res[i] = (res[prevLess[i]]) + (i - prevLess[i]) * arr[i];
        }

        int ans = 0;

        for(auto i: res) {
            ans = (ans + i) % MOD;
        }

        return ans;
    }
};
