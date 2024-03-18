class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), end(points), [&](vector<int> &a, vector<int> &b){
            // if(a[0] == b[0]) {
            //     return a[1] < b[1];
            // }

            return a[1] < b[1];
        });

        int cnt = 0;
        int currMax = INT_MIN;

        for(auto &i: points) {
            int &l = i[0];
            int &r = i[1];

            if(cnt == 0 or currMax < l) {
                currMax = r;
                cnt++;
            }
        }

        return cnt;
    }
};
