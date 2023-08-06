class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for(auto &i: word1) {
            mp1[i]++;
        }
        for(auto &i: word2) {
            mp2[i]++;
        }

        for(auto &i:mp1) {
            bool found = false;
            bool found2 = false;
            for(auto &j: mp2) {
                if(i.first == j.first) {
                    found = true;
                }
                if(i.second == j.second && (i.second!=-1 && j.second!=-1)) {
                    found2 = true;
                    i.second=-1;
                    j.second=-1;
                }
            }
            if(!found || !found2) {
                return false;
            }
        }

        return true;
    }
};
