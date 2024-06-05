class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<unordered_map<char, int>> mps(words.size(), unordered_map<char, int>());

        for(int i=0; i<words.size(); i++) {
            for(auto j: words[i]) {
                mps[i][j]++;
            }
        }

        vector<string> ans;

        int n = words.size();

        for(int i=0; i<n; i++) {
            for(auto &[k, v]: mps[i]) {
                int m = INT_MAX;
                for(int j=0; j<n; j++) {
                    if(i != j) {
                        m = min(m, mps[j][k]);
                    }
                }

                m = min(m, mps[i][k]);

                if(m != 0) {
                    while(m--) {
                        string s = "";
                        s += k;
                        ans.push_back(s);
                        for(int i=0; i<n; i++) {
                            mps[i][k]--;
                        }
                    }
                }
            }

        }

        return ans;
    }
};
