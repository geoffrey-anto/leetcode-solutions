class Solution {
public:
long long MOD = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        int maxSq = -1;

        h.push_back(m);
        v.push_back(n);

        h.push_back(1);
        v.push_back(1);

        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        unordered_set<int> st;

        for(auto &i: h) {
            for(auto &j: h) {
                st.insert(abs(i-j));
            }
        }

        long long ans = 0;

        for(auto i=0; i<v.size(); i++) {
            for(auto j=0; j<v.size(); j++) {
                if(i!=j && st.find(v[i] - v[j]) != st.end()) {
                    ans = max(ans, (long long)abs(v[i] - v[j]));
                }
            }
        }
        
        return ans == 0 ? -1 : ((ans*ans) % MOD);
    }
};