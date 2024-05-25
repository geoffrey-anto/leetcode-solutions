class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        // b1 -> c1 -> cnt1
        //      >
        //    /
        //  b2 
        // b3 -> c2 -> cnt2
        unordered_map<int, int> bc; 
        unordered_map<int, int> cc;
        vector<int> ans;

        for (auto& query : queries) {
            int b = query[0], currCol = query[1];

            if (bc.find(b) != bc.end()) {
                int c = bc[b];
                cc[c]--;
                if (!cc[c]) {
                    cc.erase(c);
                }
            }

            bc[b] = currCol;
            cc[currCol]++;

            ans.push_back(cc.size());
        }

        return ans;
    }
};
