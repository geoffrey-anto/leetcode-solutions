class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);
        set<pair<int, int>> st;

        for(auto i: roads) {
            deg[i[0]]++;
            deg[i[1]]++;
            st.insert({i[0], i[1]});
        }

        int ans = INT_MIN;

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int sum = deg[i] + deg[j];

                if(st.find({i, j}) != st.end() or st.find({j, i}) != st.end()) {
                    sum -= 1;
                }

                ans = max(ans, sum);
            }
        }


        return ans;
    }
};
