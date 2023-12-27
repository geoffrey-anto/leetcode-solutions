class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
    int ans = neededTime[0];
    int cnt = neededTime[0];

    char prev = colors[0];

    int n = colors.size();

    for (int i = 1; i < n; i++) {
        if (colors[i] != prev) {
            ans -= cnt;
            cnt = 0;
        }

        ans += neededTime[i];
        cnt = max(cnt, neededTime[i]);

        prev = colors[i];
    }
    return ans - cnt;
}
};