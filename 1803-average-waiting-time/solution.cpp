class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        double ans = c[0][1];

        int curr = c[0][0] + c[0][1];

        for(int i=1; i<c.size(); i++) {
            int& a = c[i][0];
            int& b = c[i][1];

            ans += max(a, curr) + b - a;
            curr = max(a, curr) + b;
        }

        return ans / (double)c.size();
    }
};
