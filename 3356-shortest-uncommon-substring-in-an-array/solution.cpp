class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        vector<unordered_set<string>> mp(arr.size());

        for(auto k=0; k<n; k++) {
            int s = arr[k].size();

            for(int i=0; i<s; i++) {
                string str = "";
                for(int j=i; j<s; j++) {
                    str+=arr[k][j];
                    mp[k].insert(str);
                }
            }
        }

        vector<string> ans(n, "");

        for(int i=0; i<n; i++) {
            for(auto &s: mp[i]) {
                bool flg = true;

                for (int j = 0; j < n; ++j) {
                    if (i != j && mp[j].count(s)) {
                        flg = false;
                        break;
                    }
                }

                int l = s.size();

                if (flg && (ans[i] == "" || l < ans[i].size() || (l == ans[i].size() && s < ans[i]))) {
                    ans[i] = s;
                }


            }
        }

        return ans;
    }
};
