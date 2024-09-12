class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        unordered_set<char> st(begin(allowed), end(allowed));

        for(auto &i: words) {
            bool flg = true;
            for(auto j: i) {
                if(st.find(j) == st.end()) {
                    flg = false;
                    break;
                }
            }

            if(flg)
                ans ++;
        }

        return ans;
    }
};
