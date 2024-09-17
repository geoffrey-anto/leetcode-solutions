class Solution {
public:
    vector<string> split(string &a) {
        vector<string> ans;

        stringstream ss(a);

        string buf;

        while(getline(ss, buf, ' ')) {
            ans.push_back(buf);
        }

        return ans;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m1, m2;

        auto a = split(s1);
        auto b = split(s2);

        for(auto i: a) {
            m1[i]++;
        }

        for(auto i: b) {
            m2[i]++;
        }

        vector<string> ans;

        for(auto i: a) {
            if(m2.count(i) == 0 and m1[i] == 1) {
                ans.push_back(i);
            }
        }

        for(auto i: b) {
            if(m1.count(i) == 0 and m2[i] == 1) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
