class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;

        vector<int> pre(arr.size() + 1, 0);

        for(int i=1; i<arr.size(); i++) {
            arr[i] ^= arr[i-1];
        }

        for(auto &q: queries) {
            int l = q[0];

            int r = q[1];

            if(l == 0) {
                ans.push_back(arr[r]);
                continue;
            }

            int left = arr[l-1];

            int right = arr[r];

            ans.push_back(right ^ left);
        }

        return ans;
    }
};
