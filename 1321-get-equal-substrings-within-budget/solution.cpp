class Solution {
public:
    int minCostToChangeSubstrOfSizeL(string s, string t, int l) {
        int n = s.size();

        int cost = 0;

        for(int i=0; i<l; i++) {
            cost += abs(s[i] - t[i]);
        }

        int ans = cost;

        for(int i=l; i<n; i++) {
            cost += abs(s[i] - t[i]);
            cost -= abs(s[i-l] - t[i-l]);

            ans = min(ans, cost);
        }

        return ans;
    }
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        // n log n?

        int l = 0;

        int r = n;
        int ans = n;

        while(l <= r) {
            int m = l + ((r - l)/2);

            int cost = minCostToChangeSubstrOfSizeL(s, t, m);

            if(cost > maxCost) {
                r = m-1;
            } else {
                ans = m;
                l = m+1;
            }
        }

        return ans;
    }
};
