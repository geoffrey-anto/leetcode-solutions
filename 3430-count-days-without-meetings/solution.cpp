class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &arr) {
        sort(begin(arr), end(arr));

        vector<vector<int>> ans;

        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (ans.empty() or ans.back()[1] < arr[i][0]) {
            ans.push_back(arr[i]);
            } else if (ans.back()[1] >= arr[i][0]) {
            vector<int> b = ans.back();
            ans.pop_back();

            int right = max(b[1], arr[i][1]);

            ans.push_back({b[0], right});
            }
        }

        return ans;
    }

    int countDays(int days, vector<vector<int>>& meetings) {
        // sort(begin(meetings), end(meetings));

        vector<vector<int>> m = merge(meetings);

        // for(auto &i: meetings) {
        //     if(m.size() == 0) {
        //         m.push_back(i);
        //     } else {
        //         auto x = m.back();
        //         if(x[1] >= i[0]) {
        //             x[1] = i[1];
        //             m.pop_back();
        //             m.push_back(x);
        //         } else {
        //             m.push_back(i);
        //         }

        //     }
        // }

        // for(auto &i: m) {
        //     cout << i[0] << " " << i[1] << endl;
        // }

        int ans = 0;

        for(int i=0; i<m.size()-1; i++) {
            ans += (m[i+1][0] - m[i][1] - 1);
        }

        ans += m.front()[0] - 0 - 1;

        ans += (days - m.back()[1]);

        return ans;
    }
};
