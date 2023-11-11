class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int n = arr.size();
        for(int i=0; i<n; i++) {
            // this case its like [1,2] and [3, 5]
            if(ans.empty() or arr[i][0] > ans.back()[1]) {
                ans.push_back(arr[i]);
            // this case is like [1, 3] and [2, 6]
            // we take [1 and for the end of interval we take the max(3,6)

            // so it becomes [1, 6]
            } else {
                auto bk = ans.back();
                int front, back;
                if(bk[1] > arr[i][1]) {
                    front = bk[0];
                    back = bk[1];
                } else {
                    front = bk[0];
                    back = arr[i][1];
                }
                ans.pop_back();
                ans.push_back({front, back});
            }
        }
        return ans;
    }
};
