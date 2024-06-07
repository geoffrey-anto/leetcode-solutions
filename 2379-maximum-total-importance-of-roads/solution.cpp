class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> deg(n, 0);

        for(auto &edge: roads) {
            deg[edge[0]]++;
            deg[edge[1]]++;
        }

        sort(begin(deg), end(deg));

        long long ans = 0;

        for(long long i=0; i<n; i++) {
            ans += (deg[i] * (i + 1));
        }

        return ans;
    }
};
