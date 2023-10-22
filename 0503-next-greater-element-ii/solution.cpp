class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        vector<int>v(n,-1);

        for(int i = 2*n - 1; i >= 0; i--)
        {
            int n_c = i%n;

            while(!st.empty() && nums[n_c] >= st.top())
            {
                st.pop();
            }

            if(!st.empty())
            {
                if (i < n)
                    v[i] = st.top();
            }

            st.push(nums[n_c]);
        }

        return v;
    }
};
