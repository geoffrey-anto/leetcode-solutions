class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indeg(n, 0);
        vector<int> outdeg(n, 0);

        for(auto &e: trust) {
            indeg[e[1] - 1]++;
            outdeg[e[0] - 1]++;
        }

        for(int i=0; i<n; i++) {
            if((indeg[i] == n-1) && (outdeg[i] == 0)) {
                return i+1;
            }
        }

        return -1;
    }
};
