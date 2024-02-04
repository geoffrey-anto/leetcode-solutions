class Solution {
public:
    void getNextSmaller(vector<int>& nums, vector<int> &nextSmall, int n) {
        stack<int> st;

        for(int i=0; i<n; i++) {
            while(!st.empty() && nums[i] < nums[st.top()]) {
                nextSmall[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }
    }

    void getPrevSmaller(vector<int>& nums, vector<int> &nextSmall, int n) {
        stack<int> st;

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[i] < nums[st.top()]) {
                nextSmall[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }
    }

    int validSubarraySize(vector<int>& nums, int thresh) {
        int n = nums.size();
        vector<int> nextSmall(n, -1);
        vector<int> prevSmall(n, -1);

        getNextSmaller(nums, nextSmall, n);
        getPrevSmaller(nums, prevSmall, n);

        for(int i=0; i<n; i++) {
            int l = prevSmall[i];
            int r = nextSmall[i];

            if(r == -1) {
                r = n;
            }

            if((double)nums[i] > (double)(thresh/(r - l - 1))) {
                return r - l - 1;
            }
        }

        return -1;
    }
};
