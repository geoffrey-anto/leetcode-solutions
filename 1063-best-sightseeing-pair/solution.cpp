class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int left = values[0];

        int ans = 0;

        for(int i=1; i<values.size(); i++) {
            ans = max(ans, values[i] + (left - 1));

            left = max(left - 1, values[i]);
        }

        return ans;
    }
};
