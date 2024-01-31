class Solution {
public:
    vector <int> nextGreaterElements(vector<int> & t) {
        int n = t.size();

        vector<int> nge(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && t[st.top()] <= t[i]) {
                st.pop();
            }

            if (!st.empty()) nge[i] = st.top();

            st.push(i);
        }
        
        return nge;
    }

    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();

        vector<int> ans = nextGreaterElements(t);

        for(int i=0; i<n; i++) {
            if(ans[i] == 0) {
                continue;
            }

            ans[i] = ans[i] - i;
        }

        return ans;
    }
};
