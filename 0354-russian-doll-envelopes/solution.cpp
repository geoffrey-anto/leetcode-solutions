class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(begin(e), end(e), [&](const vector<int> &a, vector<int> &b) {
            if(a[0] == b[0]) {
                return a[1] > b[1];
            }

            return a[0] < b[0];
        }); 

        int n = e.size();

        vector<int> prev;

        for(int i=0; i<n; i++) {
            int h = e[i][1];

            auto it = lower_bound(prev.begin(), prev.end(), h);

            int idx = it - prev.begin();

            if(idx >= prev.size()) prev.push_back(h);
            else prev[idx] = h;
        }

        return prev.size();
    }
};
