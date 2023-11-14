class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        int cnt = 0;
        sort(arr.begin(), arr.end(), [&](auto &a, auto &b) {
            return a[1] < b[1];
        });
        int prevEnd = arr[0][1];
        for(auto i=1; i<n; i++) {
            if(prevEnd > arr[i][0]) {
                cnt++;
            } else {
                prevEnd = arr[i][1];
            }
        }

        return cnt;
    }
};
