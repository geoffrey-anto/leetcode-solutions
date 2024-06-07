class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<long long, long long> m;
        long long n = edges.size();

        for(int i=0; i<n; i++) {
            m[edges[i]]+=i;
        }

        long long ans = 0;
        long long val = 0;

        for(auto &[k, v]: m) {
            if(v > ans) {
                ans = v;
                val = k;
            }
        }

        return val;
    }
};
