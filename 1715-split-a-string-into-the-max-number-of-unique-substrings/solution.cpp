class Solution {
public:
    pair<bool, int> f(int i, string &s, unordered_map<string, bool> &mem) {
        if(i == s.size()) {
            return {false, 0};
        }

        bool foundAtleastOne = false;

        auto ans = 0;

        for(int j=i; j<s.size(); j++) {
            string curr = s.substr(i, j - i + 1);

            if(mem.find(curr) != mem.end()) {
                continue;
            } else {
                mem[curr] = true;
                auto res = f(j+1, s, mem);
                mem.erase(curr);

                foundAtleastOne = true;

                if(res.first)
                    ans = max(ans, res.second + 1);

                if(j == s.size() - 1) {
                    break;
                }
            }
        }

        return !foundAtleastOne ? make_pair(false, 0) : make_pair(true, ans);
    }

    int maxUniqueSplit(string s) {
        unordered_map<string, bool> mem;

        auto ans = f(0, s, mem);

       return !ans.first ? 1 : ans.second + 1;
    }
};
