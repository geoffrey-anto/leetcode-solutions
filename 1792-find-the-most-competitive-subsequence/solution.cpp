class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;

        for(int i=0; i<nums.size(); i++) {
            while(!st.empty() && nums[i] < nums[st.top()] and nums.size() - i + st.size() > k) {
                st.pop();
            }

            if(st.size() < k)
                st.push(i);
        }

        vector<int> ans;

        while(!st.empty() && k) {
            ans.push_back(nums[st.top()]);
            st.pop();
            k--;
        }

        reverse(ans.begin(), ans.end());

        // return vector<int>(ans.begin(), ans.begin()+k);

        return ans;
    }
};
