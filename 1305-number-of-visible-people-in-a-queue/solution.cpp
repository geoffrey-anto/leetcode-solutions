class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();

        vector<int> nextGreatest(n, 0);

        stack<int> st;

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() and heights[st.top()] < heights[i]) {
                nextGreatest[i]++;
                st.pop();
            }

            if(!st.empty()) {
                nextGreatest[i]++;
            }

            st.push(i);
        }

        // for(auto i: nextGreatest) {
        //     cout << i << " ";
        // }
        // cout << endl;



        return nextGreatest;
    }
};
